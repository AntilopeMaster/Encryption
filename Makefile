# SRC = "crypt.cpp
# 	utils.cpp
# 	utils.h"

CXX=g++
EXEC= encrypt

SRC=main.cpp

HEADERS=utils.hpp \
		decode.hpp \
		encode.hpp

OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

encrypt: $(OBJ)
	$(CXX) -o $@ $< $(HEADERS)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean encrypt
