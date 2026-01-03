sort(words.begin(), words.end(),
            [](const string& a, const string& b) {
                return a.size() < b.size();
            }
        );