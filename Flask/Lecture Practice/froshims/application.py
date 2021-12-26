from flask import Flask, render_template, request, redirect
from cs50 import SQL
import os
from flask_mail import Mail, Message

app = Flask(__name__)
# For Email
# app.config["MAIL_DEFAULT_SENDER"] = os.getenv("MAIL_DEFAULT_SENDER")
# app.config["MAIL_PASSWORD"] = os.getenv("MAIL_PASSWORD")
# app.config["MAIL_PORT"] = 587
# app.config["MAIL_SERVER"] = smtp.gmail.com
# app.config["MAIL_USERNAME"] = os.getenv("MAIL_USSERNAME")
# mail = Mail(app)

db = SQL("sqlite:///froshims.db")

SPORTS = ["Dogeball", "Flag Football", 'Soccer', "Vollyball", "Ultimate Frisbee"]

@app.route("/")
def index():
    return render_template("index.html", sports = SPORTS)


@app.route("/register", methods=["POST"])
def register():
    email = request.form.get("email")
    if not email:
        return render_template("error.html", message = "Missing Name")

    sport = request.form.get("sport")
    if not sport:
        return render_template("error.html", message="Missing Sport")

    if sport not in SPORTS:
        return render_template("success.html", message= "Invalid Sport")

    db.execute("Insert into registrants (name, sport) values(?, ?)", email, sport)

    # For Mail
    # message = Message("You are registered!", recipients=[email])
    # mail.send(message)

    return redirect("/registrants")


@app.route("/registrants")
def registrants():
    rows = db.execute("select * from registrants")
    return render_template("registrants.html", rows=rows)