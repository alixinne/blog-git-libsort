BUILDDIR  = build
CXXFLAGS += -Iinclude -g -Wall -Werror -pedantic -std=c++11

EXES = $(BUILDDIR)/main
OBJS = $(BUILDDIR)/test-main.o $(patsubst src/%.cpp,$(BUILDDIR)/src-%.o,$(wildcard src/*.cpp))

all: $(EXES)

$(BUILDDIR):
	@mkdir -p $@

test: $(BUILDDIR)/main
	@echo $(BUILDDIR)/main
	@$(BUILDDIR)/main ; \
	RET=$$? ; \
	if [ $$RET -eq 0 ]; then \
		echo -e "\e[0;32mTests succeeded\e[0m" ; \
	else \
		echo -e "\e[0;31mTests failed with $$RET\e[0m" ; \
		exit $$RET ; \
	fi

$(BUILDDIR)/main: $(OBJS)
	$(LINK.cc) -o $@ $^

build/test-%.o: test/%.cpp $(BUILDDIR)
	$(COMPILE.cc) -o $@ $<

build/src-%.o: src/%.cpp $(BUILDDIR)
	$(COMPILE.cc) -o $@ $<

format:
	clang-format -i $(wildcard include/*.h) $(wildcard src/*.cpp) $(wildcard test/*.cpp)

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean format test
