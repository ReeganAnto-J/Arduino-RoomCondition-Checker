import React from 'react';
import { Line } from 'react-chartjs-2';
import {
  Chart as ChartJS,
  LineElement,
  CategoryScale,
  LinearScale,
  PointElement,
  Legend,
  Tooltip,
} from 'chart.js';

ChartJS.register(
  LineElement,
  CategoryScale,
  LinearScale,
  PointElement,
  Legend,
  Tooltip
);

const ChartComponent = ({ data }) => {
  const timestamps = data.map(feed => new Date(feed.created_at).toLocaleTimeString());
  const temperatures = data.map(feed => parseInt(feed.field1, 10));
  const humidity = data.map(feed => parseInt(feed.field2, 10));
  const lightIntensity = data.map(feed => parseFloat(feed.field3));

  const chartData = {
    labels: timestamps,
    datasets: [
      {
        label: 'Temperature (°C)',
        data: temperatures,
        borderColor: 'rgba(255, 99, 132, 1)',
        backgroundColor: 'rgba(255, 99, 132, 0.2)',
        yAxisID: 'y-axis-1',
      },
      {
        label: 'Humidity (%)',
        data: humidity,
        borderColor: 'rgba(54, 162, 235, 1)',
        backgroundColor: 'rgba(54, 162, 235, 0.2)',
        yAxisID: 'y-axis-2',
      },
      {
        label: 'Light Intensity (lux)',
        data: lightIntensity,
        borderColor: 'rgba(75, 192, 192, 1)',
        backgroundColor: 'rgba(75, 192, 192, 0.2)',
        yAxisID: 'y-axis-3',
      },
    ],
  };

  const options = {
    scales: {
      'y-axis-1': {
        type: 'linear',
        position: 'left',
        ticks: {
          beginAtZero: true,
        },
        title: {
          display: true,
          text: 'Temperature (°C)',
        },
      },
      'y-axis-2': {
        type: 'linear',
        position: 'right',
        ticks: {
          beginAtZero: true,
        },
        title: {
          display: true,
          text: 'Humidity (%)',
        },
        grid: {
          drawOnChartArea: false,
        },
      },
      'y-axis-3': {
        type: 'linear',
        position: 'right',
        ticks: {
          beginAtZero: true,
        },
        title: {
          display: true,
          text: 'Light Intensity (lux)',
        },
        grid: {
          drawOnChartArea: false,
        },
      },
    },
  };

  return <Line data={chartData} options={options} />;
};

export default ChartComponent;
