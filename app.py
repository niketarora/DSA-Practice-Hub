import streamlit as st


def recommend(movie_name):
    """
    Placeholder recommendation function.
    Replace this with your actual ML-based recommendation logic.
    Returns a list of 5 recommended movie names, or raises ValueError
    if the movie is not found in the dataset.
    """
    # Sample dataset used only for demonstration.
    # Replace this block with your real similarity-based lookup.
    sample_movies = {
        "The Dark Knight": ["Batman Begins", "Inception", "Interstellar", "The Prestige", "Man of Steel"],
        "Inception": ["The Dark Knight", "Interstellar", "Memento", "Shutter Island", "The Prestige"],
        "Titanic": ["The Notebook", "A Walk to Remember", "Pearl Harbor", "Atonement", "Romeo + Juliet"],
    }
    key = movie_name.strip().title()
    if key not in sample_movies:
        raise ValueError(f"Movie '{movie_name}' not found in the dataset.")
    return sample_movies[key]


def main():
    st.set_page_config(
        page_title="AI Powered Movie Recommender System",
        page_icon="🎬",
        layout="centered",
    )

    st.title("🎬 AI Powered Movie Recommender System")
    st.subheader("Which movie do you like?")

    st.write("")

    movie_input = st.text_input(
        label="Enter a movie name",
        placeholder="e.g. The Dark Knight",
    )

    st.write("")

    if st.button("Recommend", use_container_width=True):
        if not movie_input.strip():
            st.warning("⚠️ Please enter a movie name before clicking Recommend.")
        else:
            try:
                recommendations = recommend(movie_input.strip())
                st.success(f"Movies similar to **{movie_input.strip()}**:")
                st.write("")
                for i, movie in enumerate(recommendations, start=1):
                    st.markdown(f"**{i}.** {movie}")
            except ValueError:
                st.error(
                    f"❌ Sorry, **\"{movie_input.strip()}\"** was not found in our database. "
                    "Please try a different movie name."
                )


if __name__ == "__main__":
    main()
