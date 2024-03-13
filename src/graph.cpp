/*!****************************************************************************\

  \file   graph.c
  \author Dominic Severe
  \date   3-9-2024

  \par            email:  dominicsevere\@gmail.edu
  \par          project:  SolveMate

  \brief
      A self implimenet of graphs
  
      Functions include:
  
         +
  
    Cohesive Responsibility:
      graphs and management
  
    Notable portions:
       
  
\******************************************************************************/
#include <vector>  /* needed for GraphList */
#include <utility> /* std::pair */
//#include <new>
namespace DominicsSelfImplement
{   
    template<class T>
    GraphMatrix<T>::GraphMatrix()
        : _size(0)
    {
        
    }

    template<class T>
    GraphMatrix<T>::~GraphMatrix()
    {

    }

    template<class T>
    std::vector<T> GraphMatrix<T>::getEdges(int index)
    {

    }

    template<class T>
    std::pair<int, T> GraphMatrix<T>::getVert(int index)
    {

    }
    // create matrix from two vectors?
    // add vertex, 
    template<class T>
    GraphMatrix<T> GraphMatrix<T>::addVertex(T data, std::vector<int> edges)
    {

    }
    // add edge
    template<class T>
    GraphMatrix<T> GraphMatrix<T>::addEdge(int index, int edge, int weight)
    {

    }
}

