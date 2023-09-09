from flask import Flask, request, jsonify 
 
app = Flask(__name__) 
 
@app.route("/calculator/greeting", methods=['GET']) 
def greeting(): 
    return "Hello, World!", 200 
 
@app.route("/calculator/add", methods=['POST']) 
def add(): 
    try: 
        data = request.get_json() 
        if "first" in data and "second" in data: 
            first = data["first"] 
            second = data["second"] 
             result = first + second 
            response_data = {"result": result} 
            return jsonify(response_data), 200 
        else: 
            return "Invalid JSON format", 400 
    except Exception as e: 
        return str(e), 500 
 
@app.route("/calculator/subtract", methods=['POST']) 
def subtract(): 
    try: 
        data = request.get_json() 
        if "first" in data and "second" in data: 
            first = data["first"] 
            second = data["second"] 
            result = first - second 
            response_data = {"result": result} 
            return jsonify(response_data), 200 
        else: 
            return "Invalid JSON format", 400 
    except Exception as e:
