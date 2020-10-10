#!/usr/bin/env python3

# from https://mpi4py.readthedocs.io/en/stable/tutorial.html
from mpi4py import MPI

comm = MPI.COMM_WORLD
rank = comm.Get_rank()
size = comm.Get_size()


if rank == 0:
    print('size =', size)
    data = {'a': 7, 'b': 3.14}
    comm.send(data, dest=1, tag=11)
    comm.send(data, dest=2, tag=11)
    comm.send(data, dest=3, tag=11)
else:
    data = comm.recv(source=0, tag=11)
    print('rank',rank,'got',data)
