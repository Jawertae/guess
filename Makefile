comp = g++
objs = main.cpp
flags = -w
name = guess

ALL:$(objs)
	$(comp) $(objs) $(flags) -o $(name)
