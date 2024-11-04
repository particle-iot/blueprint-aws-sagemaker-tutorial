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

- [Overview](#overview)
- [Prerequisites](#prerequisites)
- [Setup Steps](#setup-steps)
  - [1. Configure the Hardware](#1-configure-the-hardware)
  - [2. Configure the Particle Cloud](#2-configure-the-particle-cloud)
  - [3. Set Up AWS SageMaker Integration](#3-set-up-aws-sagemaker-integration)
  - [4. Deploy and Test](#4-deploy-and-test)
- [Application Details](#application-details)
  - [Cloud Logic](#cloud-logic)
  - [Configuration in Ledger](#configuration-in-ledger)
  - [AWS SageMaker Integration](#aws-sagemaker-integration)
- [Conclusion](#conclusion)

## Setup Steps

### 1. Configure the Hardware

1. Attach the **Grove Temperature & Humidity Sensor (DHT11)** to the Particle Grove Shield.
2. Connect the Grove Shield to your Particle device (e.g., Argon or Boron).
3. Set up your Particle device in the Particle Console to ensure it is online and ready to transmit data.

### 2. Configure the Particle Cloud

1. In the **Particle Console**, navigate to your device's product and open the **Integrations** section.
2. Use the `app.yaml` configuration file provided in this repository to set up the necessary **Cloud Logic**, **Ledger Configuration**, and **Integrations**.
3. Deploy the `process_temperature_data.js` function to process the temperature data in the cloud.

### 3. Set Up AWS SageMaker Integration

1. In the `app.yaml` file, configure the **AWS SageMaker Timeseries Forecasting** integration:
   - Set up the **AWS region** and **data source URL** for the integration.
   - Define the target column for forecasting (`temperature`) and the forecast horizon.
2. Securely store your AWS credentials (`AWS_ACCESS_KEY_ID` and `AWS_SECRET_ACCESS_KEY`) and the SageMaker access token (`AWS_SAGEMAKER_TOKEN`) in **Vault**.

### 4. Deploy and Test

1. Deploy the Particle device firmware to begin data collection.
2. In the Particle Console, monitor data transmission to ensure that temperature and humidity readings are being sent to AWS SageMaker.
3. View the forecasting results in AWS SageMaker to analyze trends in temperature changes.

### AWS SageMaker Integration

The AWS SageMaker integration is set up to use SageMaker Autopilot for time-series forecasting. Key details include:
- **Forecast Horizon**: The number of future time periods to predict.
- **Data Source**: URL to the collected data stored in the Particle Cloud.
- **Instance Type**: Specifies the SageMaker instance used for processing (e.g., `ml.t2.medium`).
