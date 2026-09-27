import pandas as pd
#pip install scikit-learn
from sklearn.linear_model import LinearRegression

# 1. Create our historical data (Square footage vs. House Price)
data = {
    'Square_Feet': [1500, 1800, 2400, 3000, 3500],
    'Price': [250000, 300000, 400000, 480000, 550000]
}
df = pd.DataFrame(data)

# 2. Split into Features (X) and Target (y)
X = df[['Square_Feet']] # The input (must be a 2D structure like a DataFrame)
y = df['Price']         # The target outcome we want to predict

# 3. Initialize and Train (Fit) the Model
model = LinearRegression()
model.fit(X, y)

# 4. Make a Prediction for a brand-new house (2000 sq ft)
new_house = pd.DataFrame({'Square_Feet': [2000]})
predicted_price = model.predict(new_house)

# 5. Reveal the Math
print(f"Predicted price for a 2000 sq ft house: ${predicted_price[0]:,.2f}")
print(f"Model Weight (m): {model.coef_[0]:.2f}")
print(f"Model Bias (b): {model.intercept_:.2f}")
