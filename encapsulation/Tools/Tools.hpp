/*
** EPITECH PROJECT, 2022
** ITools.hpp
** File description:
** ITools
*/

#ifndef _TOOLS_HPP_
#define _TOOLS_HPP_

#include <vector>
#include <cassert>
#include <cstdio>
#include <fstream>
#include <memory>
#include <stdexcept>

namespace ray {
    namespace Tools {
        class Misc {
            public:
            Misc() = default;
            ~Misc() = default;

            /**
             * @brief Get a Random Value between min and max
             *
             * @param min int
             * @param max int
             * @return the random value (int)
             */
            static int getRandomValue(int min, int max);
            /**
             * @brief Set the seed for the Random generator
             *
             * @param seed unsigned int
             */
            static void setRandomSeed(unsigned int seed);
            /**
             * @brief Take a screenshot of current screen
             *
             * @param fileName filename extension defines format
             */
            static void takeScreenshot(std::string const &fileName);
            /**
             * @brief Setup init configuration flags
             *
             * @param flags unsigned int
             */
            static void setConfigFlags(unsigned int flags);
            /**
             * @brief Open URL with default system browser (if available)
             *
             * @param url std::string const
             */
            static void openURL(std::string const &url);
        };

        class Files {
            inline explicit Files(std::string &fileName) : _fileName(fileName) {};
            ~Files() = default;

            /**
             * @brief Load file data as byte array (read)
             *
             * @param bytesRead unsigned int
             * @return std::string
             */
            std::string loadFileData(unsigned int *bytesRead);
            /**
             * @brief Unload file data allocated by LoadFileData()
             *
             * @param data std::string
             */
            static void unloadFileData(std::string &data);
            /**
             * @brief Save data to file from byte array (write), returns true on success
             *
             * @param data void *
             * @param bytesToWrite  unsigned int
             * @return true
             * @return false
             */
            bool saveFileData(void *data, unsigned int bytesToWrite);
            /**
             * @brief Load text data from file (read), returns a '\0' terminated string
             *
             * @return std::string
             */
            std::string loadFileText();
            /**
             * @brief Unload file text data allocated by LoadFileText()
             *
             * @param text std::string
             */
            static void unloadFileText(std::string const &text);
            /**
             * @brief Save text data to file (write), string must be '\0' terminated, returns true on success
             *
             * @param text str::string
             * @return true
             * @return false
             */
            bool saveFileText(std::string const &text);
            /**
             * @brief Check if file exists
             *
             * @param fileName std::string const
             * @return true
             * @return false
             */
            static bool fileExists(std::string const &fileName);
            /**
             * @brief Check if a directory path exists
             *
             * @param dirPath std::string const
             * @return true
             * @return false
             */
            static bool directoryExists(std::string const &dirPath);
            /**
             * @brief Check file extension (including point: .png, .wav)
             *
             * @param fileName std::string const
             * @param ext std::string const
             * @return true
             * @return false
             */
            static bool isFileExtension(std::string const &fileName, std::string const &ext);
            /**
             * @brief Get pointer to extension for a filename string (includes dot: '.png')
             *
             * @param fileName std::string
             * @return std::string const
             */
            static std::string getFileExtension(std::string const &fileName);
            /**
             * @brief Get pointer to filename for a path string
             *
             * @param filePath std::string
             * @return std::string const
             */
            static std::string getFileName(std::string const &filePath);
            /**
             * @brief Get filename string without extension (uses static string)
             *
             * @param filePath std::string
             * @return std::string const
             */
            static std::string getFileNameWithoutExt(std::string const &filePath);
            /**
             * @brief Get full path for a given fileName with path (uses static string)
             *
             * @param filePath
             * @return std::string const
             */
            static std::string getDirectoryPath(std::string const &filePath);
            /**
             * @brief Get previous directory path for a given path (uses static string)
             *
             * @param dirPath
             * @return std::string const
             */
            static std::string getPrevDirectoryPath(std::string const &dirPath);
            /**
             * @brief Get current working directory (uses static string)
             *
             * @return std::string const
             */
            static std::string getWorkingDirectory();
            /**
             * @brief Get filenames in a directory path (memory should be freed)
             *
             * @param dirPath std::string const
             * @param count int *
             * @return std::vector<std::string> const
             */
            static std::vector<std::string> getDirectoryFiles(std::string const &dirPath, int *count);
            /**
             * @brief Clear directory files paths buffers (free memory)
             *
             */
            static void clearDirectoryFiles();
            /**
             * @brief Change working directory, return true on success
             *
             * @param dir std::string
             * @return true
             * @return false
             */
            static bool changeDirectory(std::string const &dir);
            /**
             * @brief Check if a file has been dropped into window
             *
             * @return true
             * @return false
             */
            static bool isFileDropped();
            /**
             * @brief Get dropped files names (memory should be freed)
             *
             * @param count
             * @return std::vector<std::string> const
             */
            static std::vector<std::string> getDroppedFiles(int *count);
            /**
             * @brief Clear dropped files paths buffer (free memory)
             *
             */
            static void clearDroppedFiles();
            /**
             * @brief Get file modification time (last write time)
             *
             * @param fileName std::string const
             * @return long
             */
            static long getFileModTime(std::string const &fileName);

            private:
                std::string _fileName;
        };

        class Storage {
            inline Storage() = default;
            inline ~Storage() = default;

            /**
             * @brief Save integer value to storage file (to defined position), returns true on success
             *
             * @param position unsigned int
             * @param value int
             * @return true
             * @return false
             */
            static bool saveStorageValue(unsigned int position, int value);
            /**
             * @brief Load integer value from storage file (from defined position)
             *
             * @param position unsigned int
             * @return int
             */
            static int loadStorageValue(unsigned int position);
        };
    };
};

#endif /*_TOOLS_HPP_*/