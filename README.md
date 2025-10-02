# ✋ Palmistry Master Quiz (C++)

A console-based learning tool designed to help users memorize and master the interpretations of the four main lines in palmistry: Heart, Head, Life, and Destiny.

This strict "Stickler Mode" quiz demands high precision, requiring users to recall the exact readings for 19 common palm features.

✨ Features

    Stickler Mode: Requires a 75% Jaccard Similarity match on the content of the reading. Failure on any question triggers a complete quiz restart!

    Dual Modes: Support for both Sequential and Randomized question order.

    Knowledge/Skip Mode (-k): Allows users to quickly review questions and see the answers without the strict similarity check. The prompt changes to "Press ENTER to continue."

    Robust String Matching: Employs a Jaccard Similarity algorithm after aggressively normalizing user input (lowercase, removal of punctuation) to provide fair, word-based scoring.

🛠️ Installation and Setup

Prerequisites

    A C++ compiler that supports C++11 or later (e.g., g++).

Compilation

Save the code as palmistry_quiz.cpp and compile it from your terminal:
Bash

g++ palmistry_quiz.cpp -o palmistry_quiz

🚀 Usage

Run the executable from your terminal, optionally including command-line arguments (switches) to control the quiz mode.

Command-Line Arguments (Switches)

Switch	Name	Description
-r	Randomize Mode	Questions are shuffled at the start of every quiz attempt.
-k	Skip/Knowledge Mode	Disables the similarity check. Any input (including just hitting Enter) advances and displays the correct answer.

Examples

Goal	Command
Strict, Random Order (Recommended for final mastery)	./palmistry_quiz -r
Review Mode (Quickly see all answers)	./palmistry_quiz -k

📝 Detailed Content Overview (19 Questions)

The quiz covers 19 specific readings across the Heart, Head, Life, and Destiny lines. This is the exact data set you are being tested on.

💖 Heart Line (7 Questions)

Feature	Correct Reading
Ends under First Finger:	"You hold high hopes for love. You have big ideals and a nearly perfect vision for what a true partnership should be."
Ends between First and Middle Finger:	"You've found a great emotional balance. You are able to mix your deep feelings with common sense, making you a thoughtful and stable partner."
Curved (Arches Up):	"You are warm, friendly, and naturally expressive. You find it easy and comfortable to show the world how you truly feel."
Wavy (Moves Up and Down):	"Your feelings can shift or change often, which suggests you may go through many significant relationships during your life."
Deep and Clear:	"This shows you have great strength for loyalty and deep, lasting commitment. When you love, you are all in."
Broken or Has Gaps:	"I see a history of emotional setbacks here. This marks past heartbreak, separation, or a significant loss you've had to overcome."
Small Forks Upward:	"This is a great sign! It shows emotional balance and a lot of happiness or peace in your love life."

🧠 Head Line (5 Questions)

Feature	Correct Reading
Straight:	"Your mind is highly logical and practical. You rely on facts, common sense, and clear, careful plans to solve problems."
Curved (Sloping Down):	"You have a deeply creative and imaginative mind. You use intuition and new ideas to solve problems, and this may indicate artistic talents."
Long (Reaches Far Across):	"You are a deep, detailed thinker. You need to analyze all the information and details before you are comfortable making a move."
Separated from the Life Line (A Gap):	"You are a fiercely independent thinker. You are bold, confident, and you make your own plans quickly without needing permission."
Broken or Has Gaps:	"This points to a period of mental interruption or a major shift in the way you think, often caused by a significant life change."

🌳 Life Line (4 Questions)

Feature	Correct Reading
Wide and Curving (Large arc):	"You have high energy, strong vitality, and great enthusiasm for life. You are outgoing and active."
Close to the Thumb (Straighter Line):	"This suggests a more cautious and reserved nature. You prefer routine, quiet time, and may have lower physical energy reserves."
Short (Stops Midway):	"This is a common line and it absolutely does not mean a short life. It suggests your life is dynamic and feels full of frequent changes or that you are easily influenced by outside events."
Upward Lines Branching Off:	"These are wonderful! These small lines pointing up are positive signs of success, achievement, or major opportunities at that point in your life."

🛤️ Destiny Line (3 Questions)

Feature	Correct Reading
Faint, Shallow, or Absent:	"This does not mean failure. It means your path is more driven by free will and personal choices than a fixed destiny. You're adaptable and can find fulfillment anywhere!"
Starts at the Base of the Palm (Wrist):	"You are a self-made individual who establishes a clear life path early and independently."
Ends under the Middle Finger (Saturn):	"This is the ideal finish, indicating long-term stability, success, and high professional achievement."

🤝 Contribution

Feel free to fork this repository, suggest new palmistry readings, or improve the string matching and quiz flow! Pull requests are welcome.
