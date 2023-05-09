CFLAGS   = -Wall -g -std=gnu99
INCLUDES = -I .
OBJDIR   = obj

CLIENT_SRCS = defines.c err_exit.c shared_memory.c semaphore.c fifo.c debug.c F4Client.c
CLIENT_OBJS = $(addprefix $(OBJDIR)/, $(CLIENT_SRCS:.c=.o))

SERVER_SRCS = defines.c err_exit.c shared_memory.c semaphore.c fifo.c debug.c F4Server.c
SERVER_OBJS = $(addprefix $(OBJDIR)/, $(SERVER_SRCS:.c=.o))

all: $(OBJDIR) F4Client F4Server

F4Client: $(CLIENT_OBJS)
	@echo "Making executable: "$@
	@$(CC) $^ -o $@  -lm

F4Server: $(SERVER_OBJS)
	@echo "Making executable: "$@
	@$(CC) $^ -o $@  -lm


$(OBJDIR):
	@mkdir -p $(OBJDIR)

$(OBJDIR)/%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	@rm -vf ${CLIENT_OBJS}
	@rm -vf ${SERVER_OBJS}
	@rm -vf F4Client
	@rm -vf F4Server
	@rm -rf ${OBJDIR}
	@ipcrm -a
	@echo "Removed object files and executables..."

.PHONY: run clean
