/*!****************************************************************************\

  \file   SolveMate.c
  \author Dominic Severe
  \date   2/14/2024

  \par            email:  dominicsevere\@gmail.edu
  \par          project:  SolveMate

  \brief
      For now just a driver for testing Graphs
  
      Functions include:
  
         +main
  
    Cohesive Responsibility:
      Start of program
  
    Notable portions:
      Nothing worth mentioning 

\******************************************************************************/
/**********************************************************\
 *    Includes 
\**********************************************************/
#include "graph.h"
/**********************************************************\
 *    Macros  
\**********************************************************/
//Silences Unused Parameter in a fun and healthy way
#define UNUSED(expr) (void)(expr)

//Namespace Shortenner because alias is gross.
namespace dsi = DominicsSelfImplement; 

int main(int argc, char const *argv[])
{
    UNUSED(argc);
    UNUSED(argv);
    dsi::GraphMatrix<int> intGraph;
    return 0;
}