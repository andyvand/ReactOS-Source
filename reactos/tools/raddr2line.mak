RADDR2LINE_BASE = $(TOOLS_BASE)
RADDR2LINE_BASE_ = $(RADDR2LINE_BASE)$(SEP)

RADDR2LINE_INT = $(INTERMEDIATE_)$(RADDR2LINE_BASE)
RADDR2LINE_INT_ = $(RADDR2LINE_INT)$(SEP)
RADDR2LINE_OUT = $(OUTPUT_)$(RADDR2LINE_BASE)
RADDR2LINE_OUT_ = $(RADDR2LINE_OUT)$(SEP)

RADDR2LINE_TARGET = \
	$(RADDR2LINE_OUT_)raddr2line$(EXEPOSTFIX)

RADDR2LINE_SOURCES = \
	$(RADDR2LINE_BASE_)raddr2line.c \
	$(RADDR2LINE_BASE_)rsym_common.c

RADDR2LINE_OBJECTS = \
	$(addprefix $(INTERMEDIATE_), $(RADDR2LINE_SOURCES:.c=.o))

RADDR2LINE_HOST_CFLAGS = $(TOOLS_CFLAGS)

RADDR2LINE_HOST_LFLAGS = $(TOOLS_LFLAGS)

.PHONY: raddr2line
raddr2line: $(RADDR2LINE_TARGET)

$(RADDR2LINE_TARGET): $(RADDR2LINE_OBJECTS) | $(RADDR2LINE_OUT)
	$(ECHO_LD)
	${host_gcc} $(RADDR2LINE_OBJECTS) $(RADDR2LINE_HOST_LFLAGS) -o $@

$(RADDR2LINE_INT_)raddr2line.o: $(RADDR2LINE_BASE_)raddr2line.c | $(RADDR2LINE_INT)
	$(ECHO_CC)
	${host_gcc} $(RADDR2LINE_HOST_CFLAGS) -c $< -o $@

#$(RADDR2LINE_INT_)rsym_common.o: $(RADDR2LINE_BASE_)rsym_common.c | $(RADDR2LINE_INT)
#	$(ECHO_CC)
#	${host_gcc} $(RADDR2LINE_HOST_CFLAGS) -c $< -o $@

.PHONY: raddr2line_clean
raddr2line_clean:
	-@$(rm) $(RADDR2LINE_TARGET) $(RADDR2LINE_OBJECTS) 2>$(NUL)
clean: raddr2line_clean
