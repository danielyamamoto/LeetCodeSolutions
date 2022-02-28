class Solution {
public:   
    string longestPalindrome(string S) {
        // Crea otro string con | entre los chars
        string SA;
        for (int i = 0; i < S.size(); i++) {
            SA.append("|");
            SA.push_back(S[i]);
        }
        SA.append("|");
        vector<int> palindromeRadius(SA.size(), 0);
        // Inicia el centro al inicio del string 
        int center = 0, radius = 0;
        int oldCenter, oldRadius, mirroredCenter, maxMirroredRadius;
    
        while (center < SA.size()) {
            // Ve si es posible ir ampliando el radio, revisando que no se salgan de los tamaños y que sean iguales en ambos lados 
            while (center-(radius+1) >= 0 && center+(radius+1) < SA.size() && SA[center-(radius+1)] == SA[center+(radius+1)]) {
                radius = radius+1;
            }
        
            // Lo guarda en un vector
            palindromeRadius[center] = radius;

            oldCenter = center;
            oldRadius = radius;
            center = center+1;
            radius = 0;

            // Se usan los datos calculados anteriormente para calcular el nuevo centro
            while (center <= oldCenter + oldRadius) {
                mirroredCenter = oldCenter - (center - oldCenter);
                maxMirroredRadius = oldCenter + oldRadius - center;
                if (palindromeRadius[mirroredCenter] < maxMirroredRadius) {
                    palindromeRadius[center] = palindromeRadius[mirroredCenter];
                    center = center+1;
                }
                else if (palindromeRadius[mirroredCenter] > maxMirroredRadius) {
                    palindromeRadius[center] = maxMirroredRadius;
                    center = center+1;
                }
                else {
                    radius = maxMirroredRadius;
                    break;
                }
            }
        }

        // Se busca en el vector el palíndrome más grande
        int maxElementIndex = max_element(palindromeRadius.begin(), palindromeRadius.end()) - palindromeRadius.begin();
        double max = *max_element(palindromeRadius.begin(), palindromeRadius.end());
        
        int tmp = (maxElementIndex-max)/2+1 == 0 ? 0 : (maxElementIndex-max)/2;
        string result = S.substr(tmp, max);
        return result;
    }
};