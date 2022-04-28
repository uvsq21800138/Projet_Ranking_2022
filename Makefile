NAME		:= ranking
BUILD_DIR	:= .build
EXT			:= c
SRC_DIR		:= src
CFLAGS		:= -Wall -Wextra -Werror -Ofast -MMD -MP -DNDEBUG
SRC			:= $(wildcard $(SRC_DIR)/*$(EXT))
OBJ			:= $(SRC:$(SRC_DIR)/%.$(EXT)=$(BUILD_DIR)/%.o)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

all: $(NAME)

clean:
	rm -rf $(BUILD_DIR) $(NAME)

re: clean all

run: $(NAME)
	./$< data/wb-cs-stanford.txt wb-cs-st.txt 

$(BUILD_DIR):
	mkdir $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.$(EXT) | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

-include $(OBJ:%.o=%.d)

.PHONY: all clean re run
