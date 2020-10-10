

# 
.PHONY: help clean webserver typehints flake8 pylint doctest mccabe

help:
	@echo "make help"
	@echo "      this message"
	@echo "==== Targets outside container ===="
	@echo "make docker"
	@echo "      build and run docker"
	@echo "make dockerlive"
	@echo "      build and run docker /bin/bash"
	@echo "==== Targets inside container ===="


docker:
	docker build -t mpi4py_phusion .
	docker run -it --rm \
           -v`pwd`:/scratch \
           mpi4py_phusion

dockerlive:
	docker build -t mpi4py_phusion .
	docker run -it --rm -v`pwd`:/scratch \
           --entrypoint='' \
           mpi4py_phusion /bin/bash
