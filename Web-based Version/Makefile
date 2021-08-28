CC=g++
STD=-std=c++11 -Wall -pedantic
CF=$(STD)
BUILD_DIR=build

all: $(BUILD_DIR) server.out

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) $(CF) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) $(CF) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) $(CF) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/server_main.o: server/main.cpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) $(CF) -c server/main.cpp -o $(BUILD_DIR)/server_main.o

$(BUILD_DIR)/Reply.o: ../Phase1/Network.hpp ../Phase1/functions.hpp ../Phase1/Hashtag.hpp ../Phase1/Jeek.hpp ../Phase1/Comment.hpp ../Phase1/User.hpp ../Phase1/Reply.hpp ../Phase1/Reply.cpp
	$(CC) -c ../Phase1/Reply.cpp -o $(BUILD_DIR)/Reply.o

$(BUILD_DIR)/Network.o: ../Phase1/Network.hpp ../Phase1/functions.hpp ../Phase1/Hashtag.hpp ../Phase1/Jeek.hpp ../Phase1/Comment.hpp ../Phase1/User.hpp ../Phase1/Reply.hpp ../Phase1/Network.cpp
	$(CC) -c ../Phase1/Network.cpp -o $(BUILD_DIR)/Network.o
	
$(BUILD_DIR)/functions.o: ../Phase1/Network.hpp ../Phase1/functions.hpp ../Phase1/Hashtag.hpp ../Phase1/Jeek.hpp ../Phase1/Comment.hpp ../Phase1/User.hpp ../Phase1/Reply.hpp ../Phase1/functions.cpp
	$(CC) -c ../Phase1/functions.cpp -o $(BUILD_DIR)/functions.o
	
$(BUILD_DIR)/User.o: ../Phase1/Network.hpp ../Phase1/functions.hpp ../Phase1/Hashtag.hpp ../Phase1/Jeek.hpp ../Phase1/Comment.hpp ../Phase1/User.hpp ../Phase1/Reply.hpp ../Phase1/User.cpp
	$(CC) -c ../Phase1/User.cpp -o $(BUILD_DIR)/User.o
	
$(BUILD_DIR)/Comment.o: ../Phase1/Network.hpp ../Phase1/functions.hpp ../Phase1/Hashtag.hpp ../Phase1/Jeek.hpp ../Phase1/Comment.hpp ../Phase1/User.hpp ../Phase1/Reply.hpp ../Phase1/Comment.cpp
	$(CC) -c ../Phase1/Comment.cpp -o $(BUILD_DIR)/Comment.o
	
$(BUILD_DIR)/Jeek.o: ../Phase1/Network.hpp ../Phase1/functions.hpp ../Phase1/Hashtag.hpp ../Phase1/Jeek.hpp ../Phase1/Comment.hpp ../Phase1/User.hpp ../Phase1/Reply.hpp ../Phase1/Jeek.cpp
	$(CC) -c ../Phase1/Jeek.cpp -o $(BUILD_DIR)/Jeek.o
	
$(BUILD_DIR)/Hashtag.o: ../Phase1/Network.hpp ../Phase1/functions.hpp ../Phase1/Hashtag.hpp ../Phase1/Jeek.hpp ../Phase1/Comment.hpp ../Phase1/User.hpp ../Phase1/Reply.hpp ../Phase1/Hashtag.cpp
	$(CC) -c ../Phase1/Hashtag.cpp -o $(BUILD_DIR)/Hashtag.o

$(BUILD_DIR)/Handlers.o: ../Phase1/Network.hpp ../Phase1/functions.hpp ../Phase1/Hashtag.hpp ../Phase1/Jeek.hpp ../Phase1/User.hpp server/Handlers.hpp server/Handlers.cpp
	$(CC) -c server/Handlers.cpp -o $(BUILD_DIR)/Handlers.o

server.out: $(BUILD_DIR)/Reply.o $(BUILD_DIR)/Network.o $(BUILD_DIR)/functions.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Comment.o $(BUILD_DIR)/Jeek.o $(BUILD_DIR)/Hashtag.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/server_main.o $(BUILD_DIR)/Handlers.o
	$(CC) $(CF) $(BUILD_DIR)/Reply.o $(BUILD_DIR)/Network.o $(BUILD_DIR)/functions.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Comment.o $(BUILD_DIR)/Jeek.o $(BUILD_DIR)/Hashtag.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/route.o $(BUILD_DIR)/server_main.o $(BUILD_DIR)/Handlers.o -o server.out

.PHONY: clean

clean:
	rm -rf $(BUILD_DIR) *.o *.out &> /dev/null