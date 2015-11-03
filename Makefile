

all: 
	ls | egrep -v "build|db_files|Makefile" | xargs -I % cp -r % build/%
	$(MAKE) -C build all



