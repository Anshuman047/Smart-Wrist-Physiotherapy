#ifndef UUID139148870644640
#define UUID139148870644640

/**
  * RandomForestClassifier(base_estimator=deprecated, bootstrap=True, ccp_alpha=0.0, class_name=RandomForestClassifier, class_weight=None, criterion=gini, estimator=DecisionTreeClassifier(), estimator_params=('criterion', 'max_depth', 'min_samples_split', 'min_samples_leaf', 'min_weight_fraction_leaf', 'max_features', 'max_leaf_nodes', 'min_impurity_decrease', 'random_state', 'ccp_alpha'), max_depth=20, max_features=sqrt, max_leaf_nodes=None, max_samples=None, min_impurity_decrease=0.0, min_samples_leaf=1, min_samples_split=2, min_weight_fraction_leaf=0.0, n_estimators=20, n_jobs=None, num_outputs=2, oob_score=False, package_name=everywhereml.sklearn.ensemble, random_state=None, template_folder=everywhereml/sklearn/ensemble, verbose=0, warm_start=False)
 */
class RandomForestClassifier {
    public:

        /**
         * Predict class from features
         */
        int predict(float *x) {
            int predictedValue = 0;
            size_t startedAt = micros();

            
                    
            uint16_t votes[2] = { 0 };
            uint8_t classIdx = 0;
            float classScore = 0;

            
                tree0(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree1(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree2(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree3(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree4(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree5(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree6(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree7(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree8(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree9(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree10(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree11(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree12(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree13(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree14(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree15(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree16(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree17(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree18(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            
                tree19(x, &classIdx, &classScore);
                votes[classIdx] += classScore;
            

            // return argmax of votes
            uint8_t maxClassIdx = 0;
            float maxVote = votes[0];

            for (uint8_t i = 1; i < 2; i++) {
                if (votes[i] > maxVote) {
                    maxClassIdx = i;
                    maxVote = votes[i];
                }
            }

            predictedValue = maxClassIdx;

                    

            latency = micros() - startedAt;

            return (lastPrediction = predictedValue);
        }

        
            

            /**
             * Predict class label
             */
            String predictLabel(float *x) {
                return getLabelOf(predict(x));
            }

            /**
             * Get label of last prediction
             */
            String getLabel() {
                return getLabelOf(lastPrediction);
            }

            /**
             * Get label of given class
             */
            String getLabelOf(int8_t idx) {
                switch (idx) {
                    case -1:
                        return "ERROR";
                    
                        case 0:
                            return "Wrong";
                    
                        case 1:
                            return "Correct";
                    
                    default:
                        return "UNKNOWN";
                }
            }


            /**
             * Get latency in micros
             */
            uint32_t latencyInMicros() {
                return latency;
            }

            /**
             * Get latency in millis
             */
            uint16_t latencyInMillis() {
                return latency / 1000;
            }
            

    protected:
        float latency = 0;
        int lastPrediction = 0;

        
            

        
            
                /**
                 * Random forest's tree #0
                 */
                void tree0(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] < 2216.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 21.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[2] < 9832.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 21.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 30.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #1
                 */
                void tree1(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[7] < 3840.0) {
                            
                                
                        if (x[5] < -256.0) {
                            
                                
                        if (x[2] < 10020.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 21.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 30.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[2] < 10130.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 21.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[11] < 1013.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 30.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[0] < -11570.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 21.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 30.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 30.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #2
                 */
                void tree2(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[0] < -12754.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 23.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[5] < 1264.5) {
                            
                                
                        if (x[8] < 9676.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 23.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 28.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 0;
                        *classScore = 23.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #3
                 */
                void tree3(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[6] < -12718.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 18.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[5] < 1436.5) {
                            
                                
                        if (x[1] < 3134.0) {
                            
                                
                        if (x[9] < -247.5) {
                            
                                
                        if (x[5] < 353.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 18.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[11] < 1550.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 18.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #4
                 */
                void tree4(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[8] < 10050.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 25.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 26.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #5
                 */
                void tree5(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[8] < 10050.0) {
                            
                                
                        if (x[3] < 312.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 23.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 28.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 28.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #6
                 */
                void tree6(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[6] < -12680.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 15.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 36.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #7
                 */
                void tree7(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] < 9552.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 20.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[3] < 540.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 31.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[0] < -12160.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 20.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #8
                 */
                void tree8(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[11] < 135.5) {
                            
                                
                        if (x[8] < 9746.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 19.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[6] < -12718.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 19.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[2] < 9512.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 19.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 32.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #9
                 */
                void tree9(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[8] < 10024.0) {
                            
                                
                        if (x[0] < -12754.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 17.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[3] < 111.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 17.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 34.0;
                        return;

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 34.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #10
                 */
                void tree10(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[0] < -12754.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 20.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 31.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #11
                 */
                void tree11(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[1] < 3422.0) {
                            
                                
                        if (x[0] < -12538.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 18.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[1] < 3850.0) {
                            
                                
                        if (x[11] < -267.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[4] < -53.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[10] < 546.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 18.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #12
                 */
                void tree12(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[6] < -12718.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 22.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[5] < 1403.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 29.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[0] < -11570.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 22.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 29.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #13
                 */
                void tree13(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[8] < 10050.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 20.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 31.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #14
                 */
                void tree14(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[8] < 10050.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 18.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #15
                 */
                void tree15(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[0] < -12632.0) {
                            
                                
                        if (x[11] < 892.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 20.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 31.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 31.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #16
                 */
                void tree16(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[2] < 9856.0) {
                            
                                
                        if (x[3] < 312.5) {
                            
                                
                        *classIdx = 0;
                        *classScore = 18.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 33.0;
                        return;

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #17
                 */
                void tree17(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[10] < -480.5) {
                            
                                
                        *classIdx = 1;
                        *classScore = 27.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[2] < 10004.0) {
                            
                                
                        if (x[3] < 235.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 24.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 27.0;
                        return;

                            
                        }

                            
                        }
                        else {
                            
                                
                        if (x[1] < 2268.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 24.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 27.0;
                        return;

                            
                        }

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #18
                 */
                void tree18(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[4] < -386.0) {
                            
                                
                        *classIdx = 1;
                        *classScore = 26.0;
                        return;

                            
                        }
                        else {
                            
                                
                        if (x[8] < 10050.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 25.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 26.0;
                        return;

                            
                        }

                            
                        }

                }
            
        
            
                /**
                 * Random forest's tree #19
                 */
                void tree19(float *x, uint8_t *classIdx, float *classScore) {
                    
                        if (x[8] < 9828.0) {
                            
                                
                        *classIdx = 0;
                        *classScore = 12.0;
                        return;

                            
                        }
                        else {
                            
                                
                        *classIdx = 1;
                        *classScore = 39.0;
                        return;

                            
                        }

                }
            
        


            
};



static RandomForestClassifier forest;


#endif