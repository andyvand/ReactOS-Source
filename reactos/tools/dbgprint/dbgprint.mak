DBGPRINT_BASE = $(TOOLS_BASE)$(SEP)dbgprint
DBGPRINT_BASE_ = $(DBGPRINT_BASE)$(SEP)
DBGPRINT_INT = $(INTERMEDIATE_)$(DBGPRINT_BASE)
DBGPRINT_INT_ = $(DBGPRINT_INT)$(SEP)
DBGPRINT_OUT = $(OUTPUT_)$(DBGPRINT_BASE)
DBGPRINT_OUT_ = $(DBGPRINT_OUT)$(SEP)

$(DBGPRINT_INT): | $(TOOLS_INT)
	$(ECHO_MKDIR)
	${mkdir} $@

ifneq ($(INTERMEDIATE),$(OUTPUT))
$(DBGPRINT_OUT): | $(TOOLS_OUT)
	$(ECHO_MKDIR)
	${mkdir} $@
endif

DBGPRINT_TARGET = \
	$(EXEPREFIX)$(DBGPRINT_OUT_)DBGPRINT$(EXEPOSTFIX)

DBGPRINT_SOURCES = $(addprefix $(DBGPRINT_BASE_), \
	dbgprint.c \
	)

DBGPRINT_OBJECTS = \
  $(addprefix $(INTERMEDIATE_), $(DBGPRINT_SOURCES:.c=.o))

DBGPRINT_HOST_CFLAGS = $(TOOLS_CFLAGS) -D__USE_W32API -Iinclude -Iinclude/reactos -Iinclude/psdk -Iinclude$(SEP)crt -Iinclude/reactos/libs -I$(INTERMEDIATE_)$(SEP)include$(SEP)psdk

DBGPRINT_HOST_LFLAGS = $(TOOLS_LFLAGS) -lntdll

.PHONY: DBGPRINT
DBGPRINT: $(DBGPRINT_TARGET)

$(DBGPRINT_TARGET): $(DBGPRINT_OBJECTS) | $(DBGPRINT_OUT)
	$(ECHO_LD)
	${host_gcc} $(DBGPRINT_OBJECTS) $(DBGPRINT_HOST_LFLAGS) -o $@

$(DBGPRINT_INT_)dbgprint.o: $(DBGPRINT_BASE_)dbgprint.c | $(DBGPRINT_INT)
	$(ECHO_CC)
	${host_gcc} $(DBGPRINT_HOST_CFLAGS) -c $< -o $@

.PHONY: DBGPRINT_clean
DBGPRINT_clean:
	-@$(rm) $(DBGPRINT_TARGET) $(DBGPRINT_OBJECTS) 2>$(NUL)
clean: DBGPRINT_clean