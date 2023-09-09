from flask import Flask, request, jsonify

app = Flask(__name__)

@app.route('/add', methods=['POST'])
def add():
    data = request.get_json()
    if not data or 'num1' not in data or 'num2' not in data:
        return jsonify({'error': 'Invalid input'}), 400
    num1 = data['num1']
    num2 = data['num2']
    result = num1 + num2
    return jsonify({'result': result}), 200

@app.route('/subtract', methods=['POST'])
def subtract():
    data = request.get_json()
    if not data or 'num1' not in data or 'num2' not in data:
        return jsonify({'error': 'Invalid input'}), 400
    num1 = data['num1']
    num2 = data['num2']
    result = num1 - num2
    return jsonify({'result': result}), 200

if __name__ == '__main__':
    app.run(debug=True)
