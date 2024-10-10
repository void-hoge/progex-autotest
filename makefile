main: main.c
	gcc main.c -o main

TESTFILES = test*

test: main $(TESTFILES)
	@echo $(TESTFILES); \
	for testfile in $(TESTFILES); \
	do \
		echo $$testfile; \
		expfile=$$(echo $$testfile | sed 's/test/exp/g'); \
		echo $$expfile; \
		outfile=$$(echo $$testfile | sed 's/test/out/g'); \
		echo $$outfile; \
		./main < $$testfile > $$outfile; \
		diff $$outfile $$expfile; \
	done

clean:
	rm main
