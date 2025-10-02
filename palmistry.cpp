#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>
#include <cctype>
#include <set>
#include <iterator>
#include <iomanip>
#include <vector>
#include <random>    // For std::shuffle and random number generation
#include <chrono>    // For a robust seed

// --- Data Structure for Questions ---

struct QuizQuestion {
    std::string name;    // e.g., "HEART LINE: Goal in Love - Ends under First Finger"
    std::string feature; // e.g., "If it ends under the First Finger:"
    std::string reading; // The required quote
};

// --- Utility Functions ---

/**
 * @brief Normalizes a string by converting to lowercase, removing punctuation 
 * (except spaces), and normalizing whitespace. This prepares the string for word-based comparison.
 */
std::string normalizeString(const std::string& str) {
    std::string temp = str;
    
    // 1. Remove punctuation (keep letters and spaces) and convert to lowercase
    std::string cleaned_str;
    for (char c : temp) {
        // Only keep alphabetic characters and spaces
        if (std::isalpha(c) || std::isspace(c)) {
            cleaned_str += static_cast<char>(std::tolower(c));
        }
    }
    
    // 2. Trim leading/trailing whitespace and normalize internal spaces
    std::stringstream ss(cleaned_str);
    std::string word;
    std::string normalized;
    while (ss >> word) {
        if (!normalized.empty()) {
            normalized += " ";
        }
        normalized += word;
    }
    
    return normalized;
}

/**
 * @brief Splits a string into a set of unique words (tokens).
 */
std::set<std::string> getWordSet(const std::string& normalized_str) {
    std::set<std::string> word_set;
    std::stringstream ss(normalized_str);
    std::string word;
    while (ss >> word) {
        // Ensure words aren't empty after cleaning
        if (word.length() > 0) {
            word_set.insert(word);
        }
    }
    return word_set;
}

/**
 * @brief Calculates the Jaccard Similarity (word-based content overlap) 
 * between two normalized strings.
 */
double calculateJaccardSimilarity(const std::string& s1, const std::string& s2) {
    // Edge case handling for empty strings
    if (s1.empty() && s2.empty()) return 1.0;
    if (s1.empty() || s2.empty()) return 0.0;
    
    std::set<std::string> set1 = getWordSet(s1);
    std::set<std::string> set2 = getWordSet(s2);

    // Calculate Intersection (words in common)
    std::set<std::string> intersection;
    std::set_intersection(set1.begin(), set1.end(),
                          set2.begin(), set2.end(),
                          std::inserter(intersection, intersection.begin()));

    // Calculate Union Size (all unique words combined)
    double union_size = static_cast<double>(set1.size() + set2.size() - intersection.size());

    // Jaccard Similarity: |Intersection| / |Union|
    double numerator = static_cast<double>(intersection.size());

    return (union_size > 0) ? (numerator / union_size) : 0.0;
}


/**
 * @brief Runs a single quiz part. Returns true on success (>= 75% similarity) 
 * and false on failure, printing the correct answer before returning.
 * @param is_skip_mode If true, any input advances the quiz (no similarity check).
 */
bool runQuizPart(int question_number,
                 const std::string& line_name,
                 const std::string& feature_description, 
                 const std::string& expected_reading,
                 bool is_skip_mode) { 
    
    const double required_similarity = 0.75; // 75% required match
    
    std::string normalized_expected = normalizeString(expected_reading);

    // --- Start of Question Block (Max Separation) ---
    std::cout << "\n\n\n"; 
    std::cout << "=======================================================\n";
    std::cout << question_number << ". " << line_name << (is_skip_mode ? " [SKIP MODE]" : "") << "\n"; 
    std::cout << "=======================================================\n";
    std::cout << "\n\n";
    
    std::string user_input;
    std::cout << feature_description << "\n\n";
    
    // --- MODIFICATION HERE: Change prompt based on skip mode ---
    if (is_skip_mode) {
        std::cout << "Press ENTER to continue: \n";
    } else {
        std::cout << "Please input the reading: \n";
    }
    // -----------------------------------------------------------
    
    std::cout << "\n>> ";
    
    std::getline(std::cin, user_input); 
    
    std::cout << "\n-------------------------------------------------------\n\n";
    
    if (is_skip_mode) {
        // --- Skip Mode Logic ---
        std::cout << "[SKIP MODE ACTIVE]\n";
        // In skip mode, we suppress the "Input received" line if input was empty (just Enter)
        if (!user_input.empty()) {
             std::cout << "Input received: '" << user_input << "'\n";
        }
        std::cout << "The correct reading was: \"" << expected_reading << "\"\n";
        std::cout << "\n*** ADVANCING *** (Skipping similarity check...)\n";
        std::cout << "\n-------------------------------------------------------\n\n";
        return true; // Always advance/succeed in skip mode
    }

    // --- Standard Quiz Mode Logic ---
    
    std::string normalized_user = normalizeString(user_input);
    double similarity_score = calculateJaccardSimilarity(normalized_user, normalized_expected);

    // --- Output Results ---
    std::cout << "[RESULT CHECK]\n";
    
    std::cout << std::fixed << std::setprecision(2); 
    std::cout << "Calculated Similarity: " << similarity_score * 100.0 << "%\n";
    
    if (similarity_score >= required_similarity) {
        std::cout << "\n*** CORRECT! *** (Required 75% match met. Proceeding...)\n";
        std::cout << "\n-------------------------------------------------------\n\n";
        return true;
    } else {
        std::cout << "\n*** INCORRECT ***\n\n";
        // Explicitly printing the answer as requested
        std::cout << "The correct reading was: \"" << expected_reading << "\"\n";
        std::cout << "\nYour answer needs to match the content closer than " << required_similarity * 100.0 << "%. \n";
        std::cout << "\n-------------------------------------------------------\n\n";
        return false; // Signal failure, triggering a full quiz restart
    }
}

/**
 * @brief Populates and returns the master list of all 19 quiz questions.
 */
std::vector<QuizQuestion> getAllQuestions() {
    return {
        // HEART LINE (1-7)
        {"HEART LINE: Goal in Love - Ends under First Finger", "If it ends under the First Finger:", "You hold high hopes for love. You have big ideals and a nearly perfect vision for what a true partnership should be."},
        {"HEART LINE: Goal in Love - Between First and Middle Finger", "If it ends between the First and Middle Finger:", "You've found a great emotional balance. You are able to mix your deep feelings with common sense, making you a thoughtful and stable partner."},
        {"HEART LINE: Expression - Curved (Arches Up)", "If it's Curved (Arches Up):", "You are warm, friendly, and naturally expressive. You find it easy and comfortable to show the world how you truly feel."},
        {"HEART LINE: Expression - Wavy (Moves Up and Down)", "If it's Wavy (Moves Up and Down):", "Your feelings can shift or change often, which suggests you may go through many significant relationships during your life."},
        {"HEART LINE: Condition - Deep and Clear", "If it is Deep and Clear:", "This shows you have great strength for loyalty and deep, lasting commitment. When you love, you are all in."},
        {"HEART LINE: Condition - Broken or Has Gaps", "If it is Broken or Has Gaps:", "I see a history of emotional setbacks here. This marks past heartbreak, separation, or a significant loss you've had to overcome."},
        {"HEART LINE: Uncommon Marks - Small Forks Upward", "Small Forks Upward:", "This is a great sign! It shows emotional balance and a lot of happiness or peace in your love life."},
        
        // HEAD LINE (8-12)
        {"HEAD LINE: Thinking Style - Straight", "If it is Straight:", "Your mind is highly logical and practical. You rely on facts, common sense, and clear, careful plans to solve problems."},
        {"HEAD LINE: Thinking Style - Curved (Sloping Down)", "If it is Curved (Sloping Down):", "You have a deeply creative and imaginative mind. You use intuition and new ideas to solve problems, and this may indicate artistic talents."},
        {"HEAD LINE: Depth of Focus - Long", "If it is Long (Reaches Far Across):", "You are a deep, detailed thinker. You need to analyze all the information and details before you are comfortable making a move."},
        {"HEAD LINE: Independence - Separated from the Life Line (A Gap)", "If it is Separated from the Life Line (A Gap):", "You are a fiercely independent thinker. You are bold, confident, and you make your own plans quickly without needing permission."},
        {"HEAD LINE: Clarity and Stress - Broken or Has Gaps", "If it is Broken or Has Gaps:", "This points to a period of mental interruption or a major shift in the way you think, often caused by a significant life change."},
        
        // LIFE LINE (13-16)
        {"LIFE LINE: Energy and Stamina - Wide and Curving (Large arc)", "If it is Wide and Curving (Makes a large arc):", "You have high energy, strong vitality, and great enthusiasm for life. You are outgoing and active."},
        {"LIFE LINE: Energy and Stamina - Close to the Thumb (Straighter Line)", "If it is Close to the Thumb (Straighter Line):", "This suggests a more cautious and reserved nature. You prefer routine, quiet time, and may have lower physical energy reserves."},
        {"LIFE LINE: Life Experiences - Short (Stops Midway)", "If it is Short (Stops Midway):", "This is a common line and it absolutely does not mean a short life. It suggests your life is dynamic and feels full of frequent changes or that you are easily influenced by outside events."},
        {"LIFE LINE: Changes and Challenges - Upward Lines Branching Off", "If it has Upward Lines Branching Off:", "These are wonderful! These small lines pointing up are positive signs of success, achievement, or major opportunities at that point in your life."},
        
        // DESTINY LINE (17-19)
        {"DESTINY LINE: Appearance - Faint, Shallow, or Absent", "If it is Faint, Shallow, or Absent:", "This does not mean failure. It means your path is more driven by free will and personal choices than a fixed destiny. You're adaptable and can find fulfillment anywhere!"},
        {"DESTINY LINE: Source of Influence - Starts at the Base of the Palm (Wrist)", "Starts at the Base of the Palm (Wrist):", "You are a self-made individual who establishes a clear life path early and independently."},
        {"DESTINY LINE: Culmination - Ends under the Middle Finger (Saturn)", "Ends under the Middle Finger (Saturn):", "This is the ideal finish, indicating long-term stability, success, and high professional achievement."}
    };
}

/**
 * @brief Runs the entire sequence of quiz parts in a given order. Returns true if all succeed, false on the first failure.
 */
bool runFullQuiz(const std::vector<QuizQuestion>& questions, bool is_randomized, bool is_skip_mode) {
    
    std::cout << "\nStarting Quiz Attempt (Mode: " << (is_randomized ? "RANDOMIZED" : "SEQUENTIAL") 
              << (is_skip_mode ? " / SKIP (-k)" : "") << ")...\n";

    for (size_t i = 0; i < questions.size(); ++i) {
        const auto& q = questions[i];
        
        // The question number is based on the current position in the sequence (1-19)
        if (!runQuizPart(static_cast<int>(i) + 1, q.name, q.feature, q.reading, is_skip_mode)) {
            return false; // Failure on this question (only relevant if not in skip mode)
        }
    }

    return true; // All parts passed
}

int main(int argc, char* argv[]) {
    // We clear cin buffer *before* the while loop starts to ensure clean initial input
    std::cin.tie(NULL); 
    std::ios_base::sync_with_stdio(false); 

    // --- Argument Handling ---
    bool randomize_order = false;
    bool skip_mode = false; 
    for (int i = 1; i < argc; ++i) {
        if (std::string(argv[i]) == "-r") {
            randomize_order = true;
        } else if (std::string(argv[i]) == "-k") { 
            skip_mode = true;
        }
    }

    // --- Setup Questions and Randomization ---
    std::vector<QuizQuestion> master_questions = getAllQuestions();
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine rng(seed);
    
    std::cout << "\n\n\n"; // Extra space at the start
    std::cout << "********************************************************\n";
    std::cout << "* Full Palmistry Quiz: STICKLER MASTERY MODE           *\n";
    std::cout << "* Mode: " << (randomize_order ? "RANDOMIZED (-r)" : "SEQUENTIAL") << "                 *\n";
    std::cout << "* " << (skip_mode ? "KNOWLEDGE/SKIP (-k) ACTIVE" : "STRICT MATCH REQUIRED") << "        *\n";
    std::cout << "* Failure on ANY question forces a complete restart!   *\n";
    std::cout << "********************************************************\n";

    bool quiz_complete = false;

    // In skip mode, the quiz only runs once.
    // If not in skip mode, it repeats on failure.
    while (!quiz_complete) {
        
        // Only shuffle if the -r argument was provided
        if (randomize_order) {
            std::shuffle(master_questions.begin(), master_questions.end(), rng);
        }
        
        if (runFullQuiz(master_questions, randomize_order, skip_mode)) { // PASS NEW ARGUMENT
            quiz_complete = true;
        } else {
            // Failure logic only executed if NOT in skip mode
            std::cout << "\nQuiz reset. Press ENTER to begin again.\n\n\n";
            // Clear cin buffer after failure and wait for user input
            std::cin.ignore(10000, '\n'); 
        }

        // If in skip_mode, the loop will exit after the first successful run.
        if (skip_mode) {
             break;
        }
    }

    std::cout << "\n\n\n"; // Extra space at the end
    std::cout << "********************************************************\n";
    if (skip_mode) {
         std::cout << "* QUIZ COMPLETE (Knowledge/Skip Mode -k).              *\n";
    } else {
        std::cout << "* CONGRATULATIONS! You mastered all 19 parts in order. *\n";
    }
    std::cout << "********************************************************\n";

    return 0;
}
