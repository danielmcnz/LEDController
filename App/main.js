import React, { useState } from 'react';
import { StyleSheet, View, Text, Button } from 'react-native';
import axios from 'axios';

export default function App() {
  const [message, setMessage] = useState('');

  const sendCommandToAPI = async (command) => {
    try {
      const response = await axios.post(`http://your-api-endpoint/${command}`);
      setMessage(response.data);
    } catch (error) {
      console.error('Error sending command:', error);
      setMessage('Error sending command');
    }
  };

  return (
    <View style={styles.container}>
      <Text style={styles.message}>{message}</Text>
      <View style={styles.buttonContainer}>
        <Button title="Turn On" onPress={() => sendCommandToAPI('turnOn')} />
        <Button title="Turn Off" onPress={() => sendCommandToAPI('turnOff')} />
        <Button title="Change Color" onPress={() => sendCommandToAPI('changeColor')} />
      </View>
    </View>
  );
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
    alignItems: 'center',
    justifyContent: 'center',
  },
  message: {
    marginBottom: 20,
    fontSize: 18,
  },
  buttonContainer: {
    flexDirection: 'row',
    justifyContent: 'space-between',
    width: '60%',
  },
});
