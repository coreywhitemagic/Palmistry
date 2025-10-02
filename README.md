# ✋ Palmistry 

Welcome to the **Palmistry Quiz**, a command-line program that helps you master palm reading.


---

## 🕺 Features
- 🧠 19 handcrafted palmistry questions
- 🔁 Optional randomization (`-r`) to shuffle the deck
- 🕊️ Skip mode (`-k`) to review content without pressure
- 🧮 Fuzzy matching via **Jaccard similarity** (75% required to pass)
- 💥 One wrong answer = Full restart (basic mode only!)

---

## 🔧 How to Build

Make sure you have a **C++17+** compiler installed.

### 🛠️ Compile it:

g++ -std=c++17 -o palmistry_quiz main.cpp

🚀 Run it:

./palmistry_quiz


---

⚙️ CLI Options
<br><br>
Flag	Mode
<br><br>
-r	🎲 Random Mode	Randomizes question order
<br><br>
-k	🧘 Skip Mode	Shows answers without checking for correctness
<br><br>
none	🧠 Basic Mode	Default strict mode — miss one, restart the quiz!



---

🧠 Full Question & Answer List
<br><br>
Here’s the complete list of all 19 palmistry interpretations included in the quiz:


❤️ HEART LINE (1–7)
<br><br>
1. Goal in Love – Ends under First Finger<br><br>
You hold high hopes for love. You have big ideals and a nearly perfect vision for what a true partnership should be.


2. Goal in Love – Between First and Middle Finger<br><br>
You've found a great emotional balance. You are able to mix your deep feelings with common sense, making you a thoughtful and stable partner.


3. Expression – Curved (Arches Up)<br><br>
You are warm, friendly, and naturally expressive. You find it easy and comfortable to show the world how you truly feel.


4. Expression – Wavy (Moves Up and Down)<br><br>
Your feelings can shift or change often, which suggests you may go through many significant relationships during your life.


5. Condition – Deep and Clear<br><br>
This shows you have great strength for loyalty and deep, lasting commitment. When you love, you are all in.


6. Condition – Broken or Has Gaps<br><br>
I see a history of emotional setbacks here. This marks past heartbreak, separation, or a significant loss you've had to overcome.


7. Uncommon Marks – Small Forks Upward<br><br>
This is a great sign! It shows emotional balance and a lot of happiness or peace in your love life.




---

🧠 HEAD LINE (8–12)
<br><br>
8. Thinking Style – Straight<br><br>
Your mind is highly logical and practical. You rely on facts, common sense, and clear, careful plans to solve problems.


9. Thinking Style – Curved (Sloping Down<br><br>)
You have a deeply creative and imaginative mind. You use intuition and new ideas to solve problems, and this may indicate artistic talents.


10. Depth of Focus – Long<br><br>
You are a deep, detailed thinker. You need to analyze all the information and details before you are comfortable making a move.


11. Independence – Separated from the Life Line (A Gap)<br><br>
You are a fiercely independent thinker. You are bold, confident, and you make your own plans quickly without needing permission.


12. Clarity and Stress – Broken or Has Gaps<br><br>
This points to a period of mental interruption or a major shift in the way you think, often caused by a significant life change.




---

🌿 LIFE LINE (13–16)
<br><br>
13. Energy and Stamina – Wide and Curving (Large arc)<br><br>
You have high energy, strong vitality, and great enthusiasm for life. You are outgoing and active.


14. Energy and Stamina – Close to the Thumb (Straighter Line)<br><br>
This suggests a more cautious and reserved nature. You prefer routine, quiet time, and may have lower physical energy reserves.


15. Life Experiences – Short (Stops Midway)<br><br>
This is a common line and it absolutely does not mean a short life. It suggests your life is dynamic and feels full of frequent changes or that you are easily influenced by outside events.


16. Changes and Challenges – Upward Lines Branching Off<br><br>
These are wonderful! These small lines pointing up are positive signs of success, achievement, or major opportunities at that point in your life.




---

🪄 DESTINY LINE (17–19)
<br><br>
17. Appearance – Faint, Shallow, or Absent<br><br>
This does not mean failure. It means your path is more driven by free will and personal choices than a fixed destiny. You're adaptable and can find fulfillment anywhere!


18. Source of Influence – Starts at the Base of the Palm (Wrist)<br><br>
You are a self-made individual who establishes a clear life path early and independently.


19. Culmination – Ends under the Middle Finger (Saturn)<br><br>
This is the ideal finish, indicating long-term stability, success, and high professional achievement.

---


🧞 License
<br><br>
MIT – Use it freely, remix it joyfully, just don’t sue the hand reader.


