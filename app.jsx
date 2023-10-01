import React from 'react';
import PropTypes from 'prop-types';

class App extends React.Component {
  render() {
    return (
      <div>
        <h1>Hello, world!</h1>
        <p>Welcome to my app.</p>
      </div>
    );
  }
}

App.propTypes = {
  name: PropTypes.string,
  age: PropTypes.number,
};

export default App;