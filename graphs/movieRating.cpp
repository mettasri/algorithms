#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <list>
#include <cmath>
#include <ctime>
#include <climits>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

class Movie {
  private:
    int movieId;
    float rating;
    vector<Movie*> similarMovies; // Similarity is bidirectional

  public:
    Movie(int movieId, float rating) {
      this->movieId = movieId;
      this->rating = rating;
    }

    int getId() {
      return movieId;
    }

    float getRating() {
      return rating;
    }

    void addSimilarMovie(Movie* movie) {
      similarMovies.push_back(movie);
      movie->similarMovies.push_back(this);
    }

    vector<Movie *>& getSimilarMovies() {
      return similarMovies;
    }
};

void addBestMovies(Movie& movie, int numTopRatedSimilarMovies, vector<Movie *>& recommendedMovies) {
  if(recommendedMovies.size() < numTopRatedSimilarMovies) {
    cout << "added movie id: " << movie.getId() << ", " << movie.getRating() << endl;
    recommendedMovies.push_back(&movie);
    return;
  }

  int lowest = 0;
  for(int i = 1; i < recommendedMovies.size(); ++i) {
    if(recommendedMovies[i]->getRating() < recommendedMovies[lowest]->getRating())
      lowest = i;
  }
  if(recommendedMovies[lowest]->getRating() < movie.getRating()) {
    cout << "deleted Id: " << recommendedMovies[lowest]->getId() << endl;
    recommendedMovies[lowest] = &movie;
    cout << "added movie id: " << movie.getId() << ", " << movie.getRating() << endl;
  }
}

/* 
 * @param movie Current movie.
 * @param numTopRatedSimilarMovies the maximum number of recommended movies to return.
 * @return List of top rated similar movies.
 * 
 * Assumptions I made: BFS Graph traversal
 * 
 * Description of my approach: TODO
 *
 * Runtime complexity of my approach: O(n) + O(n) = O(n)
 *
 * Justification of runtime complexity: TODO
 *
 */
static void getMovieRecommendations(Movie& movie, int numTopRatedSimilarMovies, vector<Movie *>& recommendedMovies) {
  queue<Movie*> movie_queue;
  movie_queue.push(&movie);

  std::map<int, bool> movie_map;
  while (!movie_queue.empty()) {
    Movie* m = movie_queue.front();
    movie_queue.pop();
    movie_map[m->getId()] = true;
    addBestMovies(*m, numTopRatedSimilarMovies, recommendedMovies);

    for (auto similar_movie : m->getSimilarMovies()) {
      if (!movie_map[similar_movie->getId()]) {
        movie_queue.push(similar_movie);
      }
    }
  }
}

bool movieIdCompare (Movie* a, Movie* b) { return (a->getId() < b->getId()); }

int main() {
  std::map<int, Movie*> movieMap;
  Movie* rootMovie = NULL;
  int numTopRatedSimilarMovies = 0;

  string type;
  while (cin >> type) {
    if (type.compare("movie") == 0) {
      int id;
      float rating;
      cin >> id >> rating;
      movieMap[id] = new Movie(id, rating);
    } else if (type.compare("similar") == 0) {
      int movieId1, movieId2;
      cin >> movieId1 >> movieId2;
      movieMap[movieId1]->addSimilarMovie(movieMap[movieId2]);
    } else if (type.compare("params") == 0) {
      int rootId;
      cin >> rootId >> numTopRatedSimilarMovies;
      rootMovie = movieMap[rootId];
    } else {
      // ignore comments and whitespace
    }
  }

  vector<Movie*> result;
  getMovieRecommendations(*rootMovie, numTopRatedSimilarMovies, result);
  std::sort(result.begin(), result.end(), movieIdCompare);

//  ofstream fout(getenv("OUTPUT_PATH"));
//  fout << "result";

  for (int i = 0; i < result.size(); ++i) {
    cout << " ";
    cout << result[i]->getId();
  }

//  fout << endl;
//  fout.close();

  return 0;
}

/* i/p:
 * movie 1 1.5
 * movie 2 3.6
 * movie 3 2.4
 * movie 4 4.8
 * similar 1 2
 * similar 1 3
 * similar 2 4
 * similar 3 4
 * params 2 3
 */
