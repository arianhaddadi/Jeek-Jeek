BUILD_DIR = build
SRC_DIR = src


all: $(BUILD_DIR)/main.o $(BUILD_DIR)/Reply.o $(BUILD_DIR)/Network.o $(BUILD_DIR)/functions.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Comment.o $(BUILD_DIR)/Jeek.o $(BUILD_DIR)/Hashtag.o
	g++ $(BUILD_DIR)/main.o $(BUILD_DIR)/Reply.o $(BUILD_DIR)/Network.o $(BUILD_DIR)/functions.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Comment.o $(BUILD_DIR)/Jeek.o $(BUILD_DIR)/Hashtag.o -o Application

$(BUILD_DIR)/Reply.o: $(SRC_DIR)/Network.hpp $(SRC_DIR)/functions.hpp $(SRC_DIR)/Hashtag.hpp $(SRC_DIR)/Jeek.hpp $(SRC_DIR)/Comment.hpp $(SRC_DIR)/User.hpp $(SRC_DIR)/Reply.hpp $(SRC_DIR)/Reply.cpp
	g++ -c $(SRC_DIR)/Reply.cpp -o $(BUILD_DIR)/Reply.o

$(BUILD_DIR)/Network.o: $(SRC_DIR)/Network.hpp $(SRC_DIR)/functions.hpp $(SRC_DIR)/Hashtag.hpp $(SRC_DIR)/Jeek.hpp $(SRC_DIR)/Comment.hpp $(SRC_DIR)/User.hpp $(SRC_DIR)/Reply.hpp $(SRC_DIR)/Network.cpp
	g++ -c $(SRC_DIR)/Network.cpp -o $(BUILD_DIR)/Network.o

$(BUILD_DIR)/functions.o: $(SRC_DIR)/Network.hpp $(SRC_DIR)/functions.hpp $(SRC_DIR)/Hashtag.hpp $(SRC_DIR)/Jeek.hpp $(SRC_DIR)/Comment.hpp $(SRC_DIR)/User.hpp $(SRC_DIR)/Reply.hpp $(SRC_DIR)/functions.cpp
	g++ -c $(SRC_DIR)/functions.cpp -o $(BUILD_DIR)/functions.o

$(BUILD_DIR)/User.o: $(SRC_DIR)/Network.hpp $(SRC_DIR)/functions.hpp $(SRC_DIR)/Hashtag.hpp $(SRC_DIR)/Jeek.hpp $(SRC_DIR)/Comment.hpp $(SRC_DIR)/User.hpp $(SRC_DIR)/Reply.hpp $(SRC_DIR)/User.cpp
	g++ -c $(SRC_DIR)/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Comment.o: $(SRC_DIR)/Network.hpp $(SRC_DIR)/functions.hpp $(SRC_DIR)/Hashtag.hpp $(SRC_DIR)/Jeek.hpp $(SRC_DIR)/Comment.hpp $(SRC_DIR)/User.hpp $(SRC_DIR)/Reply.hpp $(SRC_DIR)/Comment.cpp
	g++ -c $(SRC_DIR)/Comment.cpp -o $(BUILD_DIR)/Comment.o

$(BUILD_DIR)/Jeek.o: $(SRC_DIR)/Network.hpp $(SRC_DIR)/functions.hpp $(SRC_DIR)/Hashtag.hpp $(SRC_DIR)/Jeek.hpp $(SRC_DIR)/Comment.hpp $(SRC_DIR)/User.hpp $(SRC_DIR)/Reply.hpp $(SRC_DIR)/Jeek.cpp
	g++ -c $(SRC_DIR)/Jeek.cpp -o $(BUILD_DIR)/Jeek.o

$(BUILD_DIR)/Hashtag.o: $(SRC_DIR)/Network.hpp $(SRC_DIR)/functions.hpp $(SRC_DIR)/Hashtag.hpp $(SRC_DIR)/Jeek.hpp $(SRC_DIR)/Comment.hpp $(SRC_DIR)/User.hpp $(SRC_DIR)/Reply.hpp $(SRC_DIR)/Hashtag.cpp
	g++ -c $(SRC_DIR)/Hashtag.cpp -o $(BUILD_DIR)/Hashtag.o

$(BUILD_DIR)/main.o: $(SRC_DIR)/Network.hpp $(SRC_DIR)/functions.hpp $(SRC_DIR)/Hashtag.hpp $(SRC_DIR)/Jeek.hpp $(SRC_DIR)/Comment.hpp $(SRC_DIR)/User.hpp $(SRC_DIR)/Reply.hpp $(SRC_DIR)/main.cpp
	g++ -c $(SRC_DIR)/main.cpp -o $(BUILD_DIR)/main.o
clean:
	rm $(BUILD_DIR)/* Application