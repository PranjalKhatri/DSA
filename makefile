#this is a comment
BASE 	=	D:/Programs/DSA # Base directory of project
CC 		=	gcc	#C compiler
CFLAGS 	=	-O3 -WALL # compiler flags
EFILE 	=	$(BASE)/bin/m_exe	#executable file loacation
INCLS 	=	-I$(LOC)/include
LIBS 	=	$(LOC)/lib/g_lib.a \
			$(LOC)/lib/u_lib.a
LOC 	=	/usr/local
OBJS 	=	main.o 	f1.o	f2.o	f3.o

$(EFILE):	$(OBJS)
		echo "linking"
Default:	
		@echo Hi mi
