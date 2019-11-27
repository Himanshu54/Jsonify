# Usage
# make 			# compile all binay
# make clean		# remove all binary and objects


run: compile
	@echo "Run"
	./a.out test.json2
	@echo "Run Successful"

compile: 
	@echo "Compile"
	g++ format_json.cpp
	@echo "Compiled"

clean:
	@echo "Cleaning..."
	rm -rvf a.out

