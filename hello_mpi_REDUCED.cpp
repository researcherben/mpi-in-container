# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <mpi.h>

using namespace std;

int main ( int argc, char *argv[] );

//****************************************************************************80

int main ( int argc, char *argv[] )

{
  int id;
  int ierr;
  int p;
  double wtime;
//
//  Initialize MPI.
//
  ierr = MPI_Init ( &argc, &argv );

  if ( ierr != 0 )
  {
    cout << "\n";
    cout << "HELLO_MPI - Fatal error!\n";
    cout << "  MPI_Init returned nonzero ierr.\n";
    exit ( 1 );
  }
//
//  Get the number of processes.
//
  ierr = MPI_Comm_size ( MPI_COMM_WORLD, &p );
//
//  Get the individual process ID.
//
  ierr = MPI_Comm_rank ( MPI_COMM_WORLD, &id );
//
//  Process 0 prints an introductory message.
//
  if ( id == 0 ) 
  {
    cout << "\n";
    cout << "P" << id << ":  HELLO_MPI - Master process:\n";
    cout << "P" << id << ":    C++/MPI version\n";
    cout << "P" << id << ":    An MPI example program.\n";
    cout << "\n";
    cout << "P" << id << ":    The number of processes is " << p << "\n";
    cout << "\n";
  }
//
//  Every process prints a hello.
//
  if ( id == 0 ) 
  {
    wtime = MPI_Wtime ( );
  }
  cout << "P" << id << ":    'Hello, world!'\n";
//
//  Process 0 says goodbye.
//
  if ( id == 0 )
  {
    wtime = MPI_Wtime ( ) - wtime;
    cout << "P" << id << ":    Elapsed wall clock time = " << wtime << " seconds.\n";
  }
//
//  Terminate MPI.
//
  MPI_Finalize ( );
//
//  Terminate.
//
  if ( id == 0 )
  {
    cout << "\n";
    cout << "P" << id << ":  HELLO_MPI:\n";
    cout << "P" << id << ":    Normal end of execution.\n";
    cout << "\n";
//    timestamp ( );
  }
  return 0;
}
