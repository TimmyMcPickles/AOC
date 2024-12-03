
#include <algorithm>
#include <fstream>
#include <vector>
#include <iostream>

int main(){
    std::ifstream file("../input.txt");
    std::vector<int> list1, list2;
    int x, y;

    int total_duplicates = 0;
    int sim = 0;
    //list1 = {3, 4, 2, 1, 3, 3};
    //list2 = {4, 3, 5, 3, 9, 3};

    while (file >> x >> y){
        list1.push_back(x);
        list2.push_back(y);
    }
    std::sort(list1.begin(), list1.end());
    std::sort(list2.begin(), list2.end());
    for (int i = 0; i < list1.size(); i++){
        total_duplicates = 0;
        int j = 0;
        while (j < list2.size() && list1[i] > list2[j]){
            j++;
        }
        while (j < list2.size() && list1[i] == list2[j]){   // This code was mostly borrowed from reddit
            total_duplicates ++;                            // Thanks to ednl in the day 1 discussion
            j++;                                            //thread https://www.reddit.com/r/adventofcode/comments/1h44xmb/comment/lzw5k8j/?utm_source=share&utm_medium=web3x&utm_name=web3xcss&utm_term=1&utm_content=share_button
        }
        sim += list1[i] * total_duplicates;
    }

    std::cout << sim << std::endl;
    return 0;
}
