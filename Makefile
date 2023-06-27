ifndef CC
	CC := clang
endif

ifndef CFLAGS
	CFLAGS := --std=c89 -g -Wall
endif

ESCAPE        :=  \033
RED           :=  $(ESCAPE)[31m
BOLD_RED      :=  $(ESCAPE)[1;31m
GREEN         :=  $(ESCAPE)[32m
BOLD_GREEN    :=  $(ESCAPE)[1;32m
YELLOW        :=  $(ESCAPE)[33m
BOLD_YELLOW   :=  $(ESCAPE)[1;33m
BLUE          :=  $(ESCAPE)[34m
BOLD_BLUE     :=  $(ESCAPE)[1;34m
PURPLE        :=  $(ESCAPE)[35m
BOLD_PURPLE   :=  $(ESCAPE)[1;35m
CYAN          :=  $(ESCAPE)[36m
BOLD_CYAN     :=  $(ESCAPE)[1;36m
RESET_COLOUR  :=  $(ESCAPE)[0m

PWD           :=  $(shell pwd)
OBJ_DIR       :=  $(PWD)/obj
SRC_DIR       :=  $(PWD)/src
BIN_DIR       :=  $(PWD)/bin
DIRS          :=  obj obj/tools obj/gl bin
HEADERS       :=  -I./include/
LIBRARIES     :=  -lGL -lglfw3 -lm

_TARGETS      :=  glproject
_SOURCES      :=  main.c \
                  tools/debug.c tools/getopt.c tools/string.c \
                  gl/render.c gl/input.c
_OBJECTS      :=  main.o \
                  tools/debug.o tools/getopt.o tools/string.o \
                  gl/render.o gl/input.o

TARGETS       :=  $(addprefix $(BIN_DIR)/, $(_TARGETS))
SOURCES       :=  $(addprefix $(SRC_DIR)/, $(_SOURCES))
OBJECTS       :=  $(addprefix $(OBJ_DIR)/, $(_OBJECTS))

.PHONY: all

all: directories $(TARGETS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@printf "[CC] ""$(GREEN)""Building object \'$<\'""$(RESET_COLOUR)""\n"
	@$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(TARGETS): $(OBJECTS)
	@printf "[BIN] ""$(BOLD_GREEN)""Linking binary \'$@\'""$(RESET_COLOUR)""\n"
	@$(CC) $^ $(LIBRARIES) $(HEADERS) -o $@

directories: $(DIRS)

$(DIRS):
	@printf "[DIR] ""$(BLUE)""Directory ""$(BOLD_BLUE)""\'$@\'""$(RESET_COLOUR)$(BLUE)"" created""$(RESET_COLOUR).""\n"
	@mkdir -p $(PWD)/$@

clean:
	@rm -rv $(BIN_DIR) || true
	@rm -rv $(OBJ_DIR) || true

