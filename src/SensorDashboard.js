import React, { useEffect, useState } from 'react';
import axios from 'axios';
import Chart from './Chart';

const SensorDashboard = () => {
  const [data, setData] = useState([]);

  useEffect(() => {
    const fetchData = async () => {
      try {
        const response = await axios.get('https://api.thingspeak.com/channels/2566898/feeds.json?api_key=YOUR_API_KEY');
        setData(response.data.feeds);
      } catch (error) {
        console.error('Error fetching the data', error);
      }
    };

    fetchData();
    const interval = setInterval(fetchData, 5000); // Fetch new data every 5 seconds

    return () => clearInterval(interval); // Cleanup on unmount
  }, []);

  return (
    <div>
      <h1>Arduino Room Condition Checker</h1>
      <Chart data={data} />
    </div>
  );
};

export default SensorDashboard;
