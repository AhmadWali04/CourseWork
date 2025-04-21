package cp213;

import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Utilities for working with Movie objects.
 *
 * @author Ahmad Wali, 169036947, wali6947@mylaurier.ca
 * @version 2024-10-07
 */
public class MovieUtilities {

    /**
     * Counts the number of movies in each genre given in Movie.GENRES. An empty
     * movies list should produce a count array of: [0,0,0,0,0,0,0,0,0,0,0]
     *
     * @param movies List of movies.
     * @return Number of genres across all Movies. One entry for each genre in the
     *         Movie.GENRES array.
     */
	public static int[] genreCounts(final ArrayList<Movie> movies) {
	    int[] genreCount = new int[Movie.GENRES.length];

	    for (Movie movie : movies) {
	        int genre = movie.getGenre();
	        if (genre >= 0 && genre < Movie.GENRES.length) {
	            genreCount[genre]++;
	        }
	    }

	    return genreCount;
	}

    /**
     * Creates a Movie object by requesting data from a user. Uses the format:
     *
     * <pre>
    Title:
    Year:
    Director:
    Rating:
    Genres:
    0: science fiction
    1: fantasy
    ...
    10: mystery

    Enter a genre number:
     * </pre>
     *
     * @param keyboard A keyboard (System.in) Scanner.
     * @return A Movie object.
     */
	public static Movie getMovie(final Scanner keyboard) {
		//ask each individual question and create an object with it after
	    System.out.println("Title:");
	    String title = keyboard.nextLine();
	    System.out.println("Year:");
	    int year = keyboard.nextInt();
	    keyboard.nextLine(); 
	    System.out.println("Director:");
	    String director = keyboard.nextLine();
	    System.out.println("Rating:");
	    float rating = keyboard.nextFloat();
	    keyboard.nextLine(); 
	    Movie.genresMenu();
	    System.out.println("Enter a genre number:");
	    int genre = keyboard.nextInt();
	    Movie newMovie = new Movie(title, year, director, rating, genre);
	    return newMovie;
	}


    /**
     * Creates a list of Movies whose genre is equal to the genre parameter.
     *
     * @param movies List of movies.
     * @param genre  Genre to compare against.
     * @return List of movies of genre.
     */
    public static ArrayList<Movie> getByGenre(final ArrayList<Movie> movies, final int genre){
        ArrayList<Movie> filteredGenre = new ArrayList<>();
    	for (Movie movie: movies) {
    		if (movie.getGenre() == genre) {
    			filteredGenre.add(movie);
    		}
    		
    		//for all objects in the class movie, iterating through the movies
    		
    	}
	return filteredGenre;
    }

    /**
     * Creates a list of Movies whose ratings are equal to or higher than rating.
     *
     * @param movies List of movies.
     * @param rating Rating to compare against.
     * @return List of movies of rating or higher.
     */
    public static ArrayList<Movie> getByRating(final ArrayList<Movie> movies, final double rating) {
    	ArrayList<Movie> filteredRating = new ArrayList <>();
    	for(Movie movie : movies) {
    		//for all movie objects in the class movie, iterating through the arraylist paramater 'movies'
    		if(movie.getRating() >= rating) {
    			filteredRating.add(movie);
    		}
    	}

	return filteredRating;
    }
    
    

    /**
     * Creates a list of Movies from a particular year.
     *
     * @param movies List of movies.
     * @param year   Year to compare against.
     * @return List of movies of year.
     */
    public static ArrayList<Movie> getByYear(final ArrayList<Movie> movies, final int year) {
    	ArrayList<Movie> filteredYear = new ArrayList<>();
    	for(Movie movie: movies) {
    		if (movie.getYear()==year) {
    			filteredYear.add(movie);
    		}
    	}
	return filteredYear;
    }

    /**
     * Asks a user to select a genre from a list of genres displayed by calling
     * Movie.genresMenu() and returns an integer genre code. The genre must be a
     * valid index to an item in Movie.GENRES.
     *
     * @param keyboard A keyboard (System.in) Scanner.
     * @return An integer genre code.
     */
    public static int readGenre(final Scanner keyboard) {
    	Movie.genresMenu();
    	System.out.println("Enter a number 0-10 for genre");
    	int genre = keyboard.nextInt();
	return genre;
    }

    /**
     * Creates and returns a Movie object from a line of formatted string data.
     *
     * @param line A vertical bar-delimited line of movie data in the format
     *             title|year|director|rating|genre
     * @return The data from line as a Movie object.
     */
    public static Movie readMovie(final String line) {
        String regex = "[|]";
        String[] data = line.split(regex);
        String title = data[0];
        Integer year = Integer.parseInt(data[1]);
        String director = data[2];
        Double rating = Double.parseDouble(data[3]);
        Integer genre = Integer.parseInt(data[4]);
        Movie newMovie = new Movie(title,year,director,rating,genre);
	return newMovie;
    }

    /**
     * Reads a list of Movies from a file.
     *
     * @param fileIn A Scanner of a Movie data file in the format
     *               title|year|director|rating|genre
     * @return A list of Movie objects.
     */
    public static ArrayList<Movie> readMovies(final Scanner fileIn) {
    	//loop through fileIn
    	//call readMovie
    	//add all of those newMovie objects to an array List
    	ArrayList<Movie> films = new ArrayList<>();
    	while(fileIn.hasNextLine()) {
    		String data = fileIn.nextLine();
    		films.add(MovieUtilities.readMovie(data));
    	}
	return films;
    }

    /**
     * Writes the contents of a list of Movie to a PrintStream.
     *
     * @param movies A list of Movie objects.
     * @param ps     Output PrintStream.
     */
    public static void writeMovies(final ArrayList<Movie> movies, PrintStream ps) {
    	for (Movie movie : movies) {
    		ps.println(movie.toString());
    	}
	return;
    }

}
