# include <cstdlib>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <mpi.h>
// sleep
#include <unistd.h>

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
    cout << endl;
    cout << "HELLO_MPI - Fatal error!" << endl;
    cout << "  MPI_Init returned nonzero ierr." << endl;
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
    cout << "" << endl;
    cout << "P" << id << ":  HELLO_MPI - Master process:" << endl;
    cout << "P" << id << ":    C++/MPI version" << endl;
    cout << "P" << id << ":    An MPI example program." << endl;
    cout << "" << endl;
    cout << "P" << id << ":    The number of processes is " << p << "" << endl;
    cout << "" << endl;
  }
//
//  Every process prints a hello.
//
  if ( id == 0 )
  {
    wtime = MPI_Wtime ( ); // Returns an elapsed time on the calling processor
  }
  cout << "P" << id << ":    'Hello, world!'" << endl;
  usleep(3000000); // 1000000 microseconds = 1 second
//
//  Process 0 says goodbye.
//
  if ( id == 0 )
  {
    wtime = MPI_Wtime ( ) - wtime;
    cout << "P" << id << ":    Elapsed wall clock time = " << wtime << " seconds." << endl;
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
    cout << "" << endl;
    cout << "P" << id << ":  HELLO_MPI:" << endl;
    cout << "P" << id << ":    Normal end of execution." << endl;
    cout << "" << endl;
//    timestamp ( );
  }
  return 0;
}
