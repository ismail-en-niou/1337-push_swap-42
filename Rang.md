# Push Swap Range Algorithm

## Description
This algorithm is designed to efficiently sort a stack in the Push Swap project by processing elements within a calculated range.

### Steps:
1. **First Element Selection:**
   - Start processing from the first index of the stack.

2. **Define Range:**
   - Set the minimum (`min`) as `0`.
   - Set the maximum (`max`) as `sizeof(stack) * 0.05` (5% of the stack size).

3. **Find the Maximum Element & Optimize Moves:**
   - Identify the maximum element within the stack.
   - Determine the best movement to bring it to the top using either `rb` (rotate) or `rrb` (reverse rotate).
   - If the maximum element is already at the top, push it to Stack A (`pa`).

4. **Handle Stack Elements:**
   - Iterate through the stack and check each element's index.
   - If an element's index is greater than `max_range`, rotate `a` (`ra`).
   - If an element's index is less than `min_range`, push it to `b` (`pb`), rotate `b` (`rb`), and increment both `max_range` and `min_range`.
   - If an element's index is between `min_range` and `max_range`, push it to `b` (`pb`) and increment both `max_range` and `min_range`.

5. **Finalize Sorting:**
   - While `b` is not empty:
     - Find the maximum element in `b`.
     - Determine if it's in the first or second half of `b`.
     - Rotate (`rb`) or reverse rotate (`rrb`) `b` to bring it to the top.
     - Push the maximum element back to `a` (`pa`).

## Usage
- Implement this logic in your Push Swap project to improve sorting performance.
- Adjust the range calculation as needed to optimize based on different stack sizes.

## Notes
- This method helps in reducing unnecessary movements, leading to an optimized sorting process.
- Can be fine-tuned based on testing and different stack configurations.

Happy coding!

