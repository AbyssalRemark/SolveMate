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
#include <queue>   /* priority queues for simplicity..*/
#include <limits>
//#include <new>
namespace DominicsSelfImplement
{   
    template<class T>
    GraphMatrix<T>::GraphMatrix()
    {
    }

    template<class T>
    GraphMatrix<T>::GraphMatrix(std::vector<std::vector<int> > matrix, std::vector<std::pair<int, T> > vertices  )
    {
        //need to think if we want to deepcopy or not
        _matrix = matrix;
        _vertices  = vertices;
    }

    template<class T>
    GraphMatrix<T>::GraphMatrix(size_t size)
    {
        _matrix = std::vector<std::vector<int> >(size, std::vector<int>( size, 0));
    }

    template<class T>
    GraphMatrix<T>::~GraphMatrix()
    {
    }

    template<class T>
    std::vector<T> GraphMatrix<T>::getEdges(size_t index)
    {
        //first checks if index is a valid indecy
        if(_matrix.size() >= index)
            return _matrix[index];
        return std::vector<T>();
        //not even sure of thats right yet..
    }

    template<class T>
    std::pair<int, T> GraphMatrix<T>::getVert(size_t index)
    {
        if(_vertices.size() >= index)
            return _vertices[index];
        return std::pair<int, T>();   
    }
    // create matrix from two vectors?
    // add vertex, 
    template<class T>
    GraphMatrix<T>& GraphMatrix<T>::addVertex(T data, std::vector<int> edges)
    {
        //man I dont even want to deal with that yet...
    }
    // add edge
    template<class T>
    GraphMatrix<T>& GraphMatrix<T>::addEdge(size_t index, size_t edge, int weight)
    {
        _matrix[index][edge] = weight;
        return *this;
    }

    template<class T>
    GraphMatrix<T>& GraphMatrix<T>::addSymEdge(size_t index, size_t edge, int weight)
    {
        _matrix[index][edge] = weight;
        _matrix[edge][index] = weight;
        return *this;
    }

    /*==/\/\/\/\/\/\/\/\++++/\/\/\/\/\/\/\/\==*\
     *  TODO: Once templetized weight needs to be somehow determined from data..
    \*==\/\/\/\/\/\/\/\/++++\/\/\/\/\/\/\/\/==*/
    
    template<class T>
    std::vector<int> GraphMatrix<T>::dijkstras(size_t from, size_t to)
    {   
        //INT_MAX was so much easier to read...
        std::vector<int> nodes = std::vector<int>(_matrix.size(), std::numeric_limits<int>::max());
        //std::priority_queue something idk...
        //set start to 0.
        nodes[from] = 0;
        //Our variable for indexing. 
        int current = from;

        while(true)
        {

        }

    }

}

