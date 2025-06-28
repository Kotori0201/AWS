# AWS Lambda Summary

AWS Lambda lets you run code without managing servers. It handles compute resources like provisioning, scaling, and maintenance automatically. You write your code as **Lambda functions**, which execute only when needed.

---

## 🔧 Key Features

- **Fully managed**: No server or OS management required.
- **Automatic scaling**: Scales with workload.
- **Pay-per-use**: Billed based on execution time and resources used.

---

## ✅ Common Use Cases

- **Stream Processing**  
  Real-time data handling with Amazon Kinesis (e.g., log filtering, clickstream analysis, IoT telemetry).

- **Web Applications**  
  Build scalable apps with services like API Gateway, Lambda, and orchestration tools (e.g., CloudFormation, CDK, Step Functions).

- **Mobile Backends**  
  Use with API Gateway and AWS Amplify for mobile and web apps.

- **IoT Backends**  
  Handle IoT and third-party API requests serverlessly.

- **File Processing**  
  Trigger Lambda functions on S3 uploads for real-time processing.

- **Database Operations & Integration**  
  React to RDS and DynamoDB events for automation (e.g., logging, replication).

- **Scheduled Tasks**  
  Use Amazon EventBridge for cron-like scheduled tasks (e.g., maintenance, reports).

---

## ⚙️ How It Works

1. **Functions**: Code is written as Lambda functions.
2. **Permissions**: Managed using IAM roles and resource policies.
3. **Event Triggers**: Functions are triggered by events (JSON format).
4. **Execution Environment**: Runs in language-specific environments (e.g., Python, Node.js) with support for layers and extensions.

---

# AWS Lambda Layers Summary

A **Lambda layer** is a `.zip` archive that contains additional code or data, typically used for dependencies, custom runtimes, or configuration files.

---

## 📌 Why Use Layers?

- **Reduce Deployment Size**  
  Move dependencies to layers to keep deployment packages smaller and more manageable.

- **Separation of Concerns**  
  Update function logic and dependencies independently.

- **Share Dependencies**  
  Reuse the same layer across multiple functions.

- **Enable Code Editor Use**  
  Keep package size within limits to use the Lambda console code editor.

- **Lock SDK Versions**  
  Freeze a specific AWS SDK version to avoid unexpected changes.

---

## ⚠️ Note on Go and Rust

- **Avoid Using Layers for Go/Rust**  
  These functions are compiled as executables with dependencies included.  
  Using layers can increase cold start time due to manual loading of assemblies.

---

## 🛠️ How Layers Work

- Lambda **extracts** layers into the `/opt` directory at runtime.
- Supported runtimes have default paths to access content in `/opt`.
- You can attach **up to 5 layers** per function.
- Layers are only supported for **.zip file archives**.
- For **container-based** functions, include all dependencies in the image.

---

## 📚 Related Topics

- How to use layers  
- Layers and layer versions  
- Packaging your layer content  
- Creating and deleting layers  
- Adding layers to functions  
- Using CloudFormation with layers  
- Using AWS SAM with layers

---

