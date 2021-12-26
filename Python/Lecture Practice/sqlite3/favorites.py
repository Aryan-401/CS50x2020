from cs50 import SQL
import csv

open("shows_small.db", "w").close()

db = SQL("sqlite:///shows.db")
db.execute("CREATE TABLE shows (id INTEGER, title TEXT, PRIMARY KEY(id))")
db.execute("CREATE TABLE genres (show_id INTEGER, genre TEXT, FOREIGN KEY(show_id) REFERENCES shows(id))")

with open("Favorite TV Shows - Form Responses 1.csv", 'r') as file:
    reader = csv.DictReader(file)
    for row in reader:
        title = row["title"].strip().upper()

        _id = db.execute("INSERT INTO shows(title) VALUES (?)", title)
        for genre in row["genres"].split(','):
            db.execute("INSERT INTO genres (show_id, genre) values(?, ?)", _id, genre.strip())