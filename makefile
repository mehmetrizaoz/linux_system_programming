SUBDIRS := $(shell ls -F | grep /)

.PHONY: $(SUBDIRS) subdirs

subdirs: $(SUBDIRS) 

$(SUBDIRS):
	@echo $@ "is being compiling..."
	$(MAKE) --directory=$@ $(TARGET)
	@echo ""
clean:
	@echo $@ "is being cleaned..."
	$(MAKE) TARGET=clean
	@echo ""	
