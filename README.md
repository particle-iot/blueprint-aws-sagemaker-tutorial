# AWS SageMaker Time-Series Forecasting Tutorial

## Overview

This tutorial demonstrates how to set up time-series forecasting using AWS SageMaker with environmental data collected from Particle devices. Using the Grove Temperature & Humidity Sensor and AWS SageMaker's automated machine learning capabilities, you can predict future environmental trends based on temperature and humidity data. This is useful for applications such as weather prediction, industrial monitoring, and smart agriculture.

## Prerequisites

To complete this tutorial, you will need:

1. **AWS Account** with access to SageMaker services.
2. **Particle Feather-based Development Board** (e.g., Argon, Boron).
3. **Grove Temperature & Humidity Sensor (DHT11)** and **Particle Grove Shield** for connecting the sensor.
4. **Particle Console Access** to configure cloud services and integrations.

## Table of Contents

- [AWS SageMaker Time-Series Forecasting Tutorial](#aws-sagemaker-time-series-forecasting-tutorial)
  - [Overview](#overview)
  - [Prerequisites](#prerequisites)
  - [Table of Contents](#table-of-contents)
  - [Setup Steps](#setup-steps)
    - [1. Configure the Hardware](#1-configure-the-hardware)
    - [2. Set Up AWS SageMaker Integration](#2-set-up-aws-sagemaker-integration)
    - [3. Configure the Particle Cloud](#3-configure-the-particle-cloud)
    - [4. Deploy and Test](#4-deploy-and-test)
    - [AWS SageMaker Integration](#aws-sagemaker-integration)

## Setup Steps

### 1. Configure the Hardware

1. Attach the **Grove Temperature & Humidity Sensor (DHT11)** to the Particle Grove Shield.
2. Connect the Grove Shield to your Particle device (e.g., Argon or Boron).
3. Set up your Particle device in the Particle Console to ensure it is online and ready to transmit data.

### 2. Set Up AWS SageMaker Integration

1. In the **AWS Management Console**, set up **AWS SageMaker Timeseries Forecasting**.
   - Take note of the **AWS region** and **data source URL** for the integration.
   - Define the target column for forecasting (`temperature`) and the forecast horizon.
2. Note your SageMaker access token (`AWS_SAGEMAKER_TOKEN`) for use in the next step.

### 3. Configure the Particle Cloud

1.  In the **Particle Console**, navigate to your device's product
2.  Add the following integration:
  - Name: AWS SageMaker Timeseries Forecasting
  - Type: Webhook
  - Event name: env-data
  - URL: `https://sagemaker.<region>.amazonaws.com`
  - Request method: POST
  - Request format: JSON
  - Request body:
  ```
    {
    "instance_type": "ml.t2.medium",
    "data_source": "{{data_url}}",
    "target_column": "temperature",
    "forecast_horizon": 7,
    "frequency": "M"
  }
  ```
  - Headers:
    - Authorization: "Bearer AWS_SAGEMAKER_TOKEN"
3. Add a Logic Function using the code from `process_temperature_data.js` to process the temperature data in the cloud.

### 4. Deploy and Test

1. Deploy the Particle device firmware to begin data collection.
2. In the Particle Console, monitor data transmission to ensure that temperature and humidity readings are being sent to AWS SageMaker.
3. View the forecasting results in AWS SageMaker to analyze trends in temperature changes.

### AWS SageMaker Integration

The AWS SageMaker integration is set up to use SageMaker Autopilot for time-series forecasting. Key details include:
- **Forecast Horizon**: The number of future time periods to predict.
- **Data Source**: URL to the collected data stored in the Particle Cloud.
- **Instance Type**: Specifies the SageMaker instance used for processing (e.g., `ml.t2.medium`).
