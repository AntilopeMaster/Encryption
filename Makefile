# SRC = "crypt.cpp
# 	utils.cpp
# 	utils.h"

CXX=g++
EXEC= encrypt

SRC=main.cpp

HEADERS_PATH=include

HEADERS=$(HEADERS_PATH)/utils.hpp \
		$(HEADERS_PATH)/Caesar/decode.hpp \
		$(HEADERS_PATH)/Caesar/encode.hpp \
		$(HEADERS_PATH)/Swap/decode.hpp \
		$(HEADERS_PATH)/Swap/encode.hpp

OBJ= $(SRC:.cpp=.o)

all: $(EXEC)

encrypt: $(OBJ)
	$(CXX) -o $@ $< $(HEADERS)

clean: 
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean encrypt
