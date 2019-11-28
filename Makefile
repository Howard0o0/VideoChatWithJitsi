CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lm -lpaho-mqtt3c -lpaho-mqtt3a
INCLUDES= -I $(shell pwd)/inc

# user modify: subdir, target and objects
VPATH 	=  src
EXENAME =  VideoChatWithJitsi
OBJECTS	=  main.o 
OBJECTS += mqtt.o 

# make target
all:${OBJECTS}
	${CC} -o ${EXENAME} *.o ${LDFLAGS} ${INCLUDES}
	
# make clean
clean:
	rm -rf ${EXENAME} ${OBJECTS} 

# dependence	
%.o : %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@
%.o : %.cc
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $@