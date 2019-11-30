CC		= gcc
CFLAGS	= -Wall -O2 -g
LDFLAGS	= -lm -lpaho-mqtt3c -lpaho-mqtt3a -lpthread
INCLUDES= -I $(shell pwd)/inc
OBJS = objs/

# user modify: subdir, target and objects
VPATH 	=  src
EXENAME =  videoChatWithJitsi
OBJECTS	=  main.o \
			mqtt.o \
			localOpr.o \
			remoteMachine.o \



# make target
all:${OBJECTS}
	${CC} -g -o ${EXENAME} $(OBJS)*.o ${LDFLAGS} ${INCLUDES}
	
# make clean
clean:
	rm -rf ${EXENAME} $(OBJS)${OBJECTS} 

# dependence	
%.o : %.c
	${CC} ${CFLAGS} ${INCLUDES} -c $< -o $(OBJS)$@