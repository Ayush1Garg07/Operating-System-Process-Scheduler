CC = gcc
CFLAGS = -Wall -Iinclude
OBJDIR = obj
SRCDIR = src

OBJS = $(OBJDIR)/main.o \
       $(OBJDIR)/Queue.o \
       $(OBJDIR)/stats.o \
       $(OBJDIR)/FirstComeFirstServe.o \
       $(OBJDIR)/ShortestJobFirst.o \
       $(OBJDIR)/ShortestRemainingtimefirst.o \
       $(OBJDIR)/RobinRound.o \
       $(OBJDIR)/LotteryScheduling.o \
       $(OBJDIR)/MultiLevelFeedbackQueue.o

TARGET = scheduler

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR)/*.o $(TARGET)
