from flask import Flask, request, jsonify

app = Flask(__name__)

# Endpoint to check if the service is available
@app.route('/calculator/greeting', methods=['GET'])
def greeting():
    return "Hello world!"

# Endpoint to add two numbers
@app.route('/calculator/add', methods=['POST'])
def add_numbers():
    try:
        data = request.get_json()
        first = data['first']
        second = data['second']
        result = first + second
        response = {'result': result}
        return jsonify(response)
    except KeyError:
        return "Invalid request. Please provide 'first' and 'second' numbers in the request body.", 400

# Endpoint to subtract two numbers
@app.route('/calculator/subtract', methods=['POST'])
def subtract_numbers():
    try:
        data = request.json
        first = data['first']
        second = data['second']
        result = first - second
        response = {'result': result}
        return jsonify(response)
    except KeyError:
        return "Invalid request. Please provide 'first' and 'second' numbers in the request body.", 400

if __name__ == '__main__':
    app.run(port=8080,host='0.0.0.0')
