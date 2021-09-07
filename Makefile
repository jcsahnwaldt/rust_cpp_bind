run clean: structs traits both
	@:

structs traits both:
	$(MAKE) -C $@ $(MAKECMDGOALS)

.PHONY: structs traits both
