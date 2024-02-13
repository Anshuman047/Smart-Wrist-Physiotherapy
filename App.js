import React, { useState, useEffect } from "react";
import { initializeApp, getApp } from "firebase/app";
import { getDatabase, ref, onValue } from "firebase/database";
import { View, Text, StyleSheet } from "react-native";

const firebaseConfig = {
  apiKey: "AIzaSyDwOz2XxL_58qXMN6LKfotyoFaOXhuJIu0",
  authDomain: "physiohand-test.firebaseapp.com",
  databaseURL:
    "https://physiohand-test-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "physiohand-test",
  storageBucket: "physiohand-test.appspot.com",
  messagingSenderId: "1036973380876",
  appId: "1:1036973380876:web:0c35303750db96354a6529",
  measurementId: "G-EQNMJMW1NK",
};

let dataRef;

try {
  const app = initializeApp(firebaseConfig);
  const db = getDatabase(app);
  dataRef = ref(db, "data");
} catch (error) {
  const app = getApp(firebaseConfig);
  const db = getDatabase(app);
  dataRef = ref(db, "data");
}

const App = () => {
  const [state, setState] = useState([]);
  const [uniqueState, setUniqueState] = useState([]);

  useEffect(() => {
    onValue(dataRef, (snapshot) => {
      const data = snapshot.val();
      setState((prev) => [...prev, data]);
    });
  }, []);

  useEffect(() => {
    console.log(state[state.length - 1]);
    setUniqueState(
      state
        .slice()
        .reverse()
        .filter((item, index, self) => {
          return (
            self.findIndex((i) => i.CurrentTime === item.CurrentTime) === index
          );
        })
    );
  }, [state]);

  return (
    <View style={styles.container}>
      <View style={styles.resultContainer}>
        {uniqueState.map((target, index) => (
          <View style={styles.resultItem} key={index}>
            <Text style={styles.timestamp}>{target.CurrentTime}</Text>
            <Text style={styles.resultText}>{target.PredictedGesture}</Text>
          </View>
        ))}
      </View>
    </View>
  );
};

const styles = StyleSheet.create({
  container: {
    flex: 1,
    justifyContent: "center",
    alignItems: "center",
    width: "100%",
    height: "100%",
  },
  resultContainer: {
    borderWidth: 2,
    borderColor: "black",
    padding: 10,
    width: "80%",
    height: "50%",
    display: "flex",
    flexDirection: "column-reverse",
    gap: 2,
    overflow: "hidden",
  },
  resultItem: {
    display: "flex",
    flexDirection: "row",
    alignItems: "center",
  },
  resultText: {
    padding: 5,
    borderWidth: 1,
    borderColor: "gray",
    width: "50%",
    height: "100%",
    display: "flex",
    alignItems: "center",
  },
  timestamp: {
    padding: 5,
    backgroundColor: "gray",
    width: "auto",
    height: "100%",
    alignItems: "center",
  },
});

export default App;