

#
.PHONY: help clean webserver typehints flake8 pylint doctest mccabe

help:
	@echo "make help"
	@echo "      this message"
	@echo "==== Targets outside container ===="
	@echo "make dockerlive"
	@echo "      build and run docker /bin/bash"
	@echo "==== Targets inside container ===="
	@echo "make mpirun FILENAME=\"hello_mpi\""
	@echo "    "

ifdef FILENAME
	@echo 'FILENAME is defined:' $(FILENAME)
else
	@echo 'FILENAME is undefined; defaulting to hello_mpi'
	FILENAME="hello_mpi"
endif

# outside the container
docker_build:
	docker build -t mpi_phusion .

# outside the container
docker: docker_build
	docker run -it --rm \
           -v`pwd`:/scratch \
           mpi_phusion

# outside the container
dockerlive: docker_build
	docker build -t mpi_phusion .
	docker run -it --rm -v`pwd`:/scratch \
           --entrypoint='' \
           mpi_phusion /bin/bash

# inside the container
mpirun:
	mpic++ $(FILENAME).cpp
	time mpiexec -np 2 ./a.out
