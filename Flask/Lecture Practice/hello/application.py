from flask import Flask, render_template, request

app = Flask(__name__)

@app.route("/", methods=["GET", "POST"])  # GET shows in URL, POST doesn't
def index():
    if request.method == "GET":
        return render_template("index.html")
    if request.method == "POST":
        return render_template('greet.html', name=request.form.get("name", 'world'))