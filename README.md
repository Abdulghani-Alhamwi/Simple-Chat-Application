# 💬 C++ Chat App

A console-based C++ chat application for sending and receiving messages locally. Users can maintain online/offline status, track message history, and explore practical OOP concepts using maps, vectors, and pairs.

---

### 🟢 User Management :
- Create users with unique usernames.  
- Each user has a status: **Online** or **Offline**.  
- Duplicate usernames are automatically prevented.

---

### ✉️ Messaging :
- **Send Messages:** Users can send messages with a **Title** and **Body**. Sent messages are stored in `_SentMessages`.  
- **Receive Messages:** Users only receive messages when **Online**. Messages are stored in `_ReceivedMessages`.

---

### 📄 Message History :
- **Retrieve All Sent Messages:** View all messages sent by the user in a formatted display.  
- **Retrieve All Received Messages:** View all messages received while online.

---

### 🔄 Status Control :
- Change user status at any time.  
- Only **Online** users can receive messages.

---

### 🛠 Data Structures :

#### 🗺 map
- Stores messages as **Title → Body** pairs.  
- Ensures unique titles and efficient retrieval.

#### 🔗 pair
- Holds exactly two values.  
- Used to return messages as `(Title, Body)` after sending.

#### 📚 vector
- Tracks usernames to prevent duplicates.

---

### 🏗 Object-Oriented Concepts :
- **Class `clsUser`:** Encapsulates user data and behavior.  
- **Encapsulation:** Private members with public methods controlling access.  
- **Enum `enStatus`:** Represents Online/Offline status.  
- **Constructor:** Initializes users and checks for duplicates.  
- **Member Functions:** Handle sending, receiving, retrieving messages, and changing status.

---

### ⚡ Usage Example :
```cpp
int main()
{
clsUser User1("Abdulghani", clsUser::Online);
clsUser User2("Ali", clsUser::Online);

// Send and receive messages
pair<string,string> msg1 = User1.SentMessage("Welcome", "Hello Ali!");
pair<string,string> msg2 = User1.SentMessage("Our App", "This is a simple chat app.");

User2.RecieveMessage(msg1.first, msg1.second);
User2.RecieveMessage(msg2.first, msg2.second);

// Retrieve messages
User2.RetriveAllRecievedMessages();
User1.RetriveAllSentMessages();

// User2 replies
pair<string,string> msg3 = User2.SentMessage("Reply", "Hi Abdulghani, I'm good.");
User1.RecieveMessage(msg3.first, msg3.second);

// Retrieve updated messages
User1.RetriveAllRecievedMessages();
User2.RetriveAllSentMessages();

// Change status
User2.ChangeStatus(clsUser::OffLine);
cout << "User2 Status: " << User2.GetStatus() << endl;
}
